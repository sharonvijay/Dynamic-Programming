#include <iostream>
#include <vector>
using namespace std;
// Longest Common Subsequence
// Given two strings, find the length of longest subsequence present
// in both of them. Both the strings are in uppercase latin alphabets.

// Example 1:

// Input:
// A = 6, B = 6
// str1 = ABCDGH
// str2 = AEDFHR
// Output: 3
// Explanation: LCS for input strings “ABCDGH” and “AEDFHR” is “ADH” of length 3.

int lcs(int n, int m, string s1, string s2)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}
int main()
{
    string s1;
    cin >> s1;
    int n = s1.length();
    string s2;
    cin >> s2;
    int m = s2.length();

    int result = lcs(n, m, s1, s2);
    cout << "Sol lcs " << result;
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
// Longest Common Substring
// Given two strings. The task is to find the length of
// the longest common substring.

// Example 1:

// Input: S1 = "ABCDGH", S2 = "ACDGHR", n = 6, m = 6
// Output: 4
// Explanation: The longest common substring
// is "CDGH" which has length 4.
int longestCommonSubstr(string S1, string S2, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = 0;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (S1[i - 1] == S2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                ans = max(ans, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return ans;
}
int main()
{
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;
    int n = s1.length();
    int m = s2.length();
    int result = longestCommonSubstr(s1, s2, n, m);
    cout << "Length of longest common substring is " << result << endl;
    return 0;
}
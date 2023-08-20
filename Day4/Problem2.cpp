#include <iostream>
#include <vector>
using namespace std;
// Longest Palindromic Subsequence
// Input:
// S = "bbabcbcab"
// Output: 7
// Explanation: Subsequence "babcbab" is the
// longest subsequence which is also a palindrome.
int longestPalinSubseq(string A)
{
    int n = A.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1; // Single character is a palindrome
    }

    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            // i is the starting index of the current substring
            // ending index of the current substring
            int j = i + len - 1;
            if (A[i] == A[j])
            {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            }
            else
            {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[0][n - 1];
}

int main()
{
    string s;
    cout << "Enter a string: ";
    cin >> s;
    int result = longestPalinSubseq(s);
    cout << "Longest Palindromic Subsequence Length: " << result << endl;
    return 0;
}
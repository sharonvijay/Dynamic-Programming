// Unique Paths in a Grid
#include <iostream>
#include <vector>
using namespace std;
int uniquePaths1(int n, int m, vector<vector<int>> &grid)
{
    // RECURSION APPROACH
    int MOD = 1000000007;

    if (n < 1 || m < 1 || grid[n - 1][m - 1] == 0)
    {
        return 0;
    }

    if (n == 1 || m == 1)
    {
        return 1;
    }

    return (uniquePaths1(n - 1, m, grid) % MOD + uniquePaths1(n, m - 1, grid) % MOD) % MOD;
}
int uniquePaths2(int n, int m, vector<vector<int>> &grid)
{
    // DP APPROACH
    int MOD = 1000000007;

    if (grid[0][0] == 0 || grid[n - 1][m - 1] == 0)
    {
        return 0;
    }

    vector<vector<int>> dp(n, vector<int>(m, 0));
    // init destination
    // Initialize the starting cell if it's open
    if (grid[0][0] == 1)
    {
        dp[0][0] = 1;
    }

    // init first row
    for (int j = 1; j < m; j++)
    {
        if (grid[0][j] == 1)
        {
            dp[0][j] = dp[0][j - 1];
        }
    }

    // init first col
    for (int i = 1; i < n; i++)
    {
        if (grid[i][0] == 1)
        {
            dp[i][0] = dp[i - 1][0];
        }
    }

    // Fill the dp
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return dp[n - 1][m - 1];
}
int uniquePathsMemo(int n, int m, vector<vector<int>> &grid, vector<vector<int>> &memo)
{
    // MEMOIZATION APPROACH

    int MOD = 1000000007;

    if (n < 1 || m < 1 || grid[n - 1][m - 1] == 0)
    {
        return 0;
    }

    if (n == 1 && m == 1)
    {
        return 1;
    }

    if (memo[n][m] != -1)
    {
        return memo[n][m];
    }

    int uniquePathLeft = uniquePathsMemo(n - 1, m, grid, memo);
    int uniquePathUp = uniquePathsMemo(n, m - 1, grid, memo);

    memo[n][m] = (uniquePathLeft % MOD + uniquePathUp % MOD) % MOD;

    return memo[n][m];
}
int uniquePaths3(int n, int m, vector<vector<int>> &grid)
{
    vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1));
    return uniquePathsMemo(n, m, grid, memo);
}

int main()
{
    int n, m;
    cin >> n;
    cin >> m;

    vector<vector<int>> grid(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            cin >> grid[i][j];
        }
    }
    int result1 = uniquePaths1(n, m, grid);
    cout << "Sol1 No of uniquePaths are " << result1 << endl;
    int result2 = uniquePaths2(n, m, grid);
    cout << "Sol2 No of uniquePaths are " << result2 << endl;
    int result3 = uniquePaths3(n, m, grid);
    cout << "Sol3 No of uniquePaths are " << result3 << endl;
    return 0;
}
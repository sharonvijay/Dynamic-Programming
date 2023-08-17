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
    // Initialize the destination cell if it's open
    if (grid[n - 1][m - 1] == 1)
    {
        dp[n - 1][m - 1] = 1;
    }

    // init last row
    for (int j = m - 2; j >= 0; --j)
    {
        if (grid[n - 1][j] == 1)
        {
            dp[n - 1][j] = dp[n - 1][j + 1];
        }
    }

    // init last col
    for (int i = n - 2; i >= 0; --i)
    {
        if (grid[i][m - 1] == 1)
        {
            dp[i][m - 1] = dp[i + 1][m - 1];
        }
    }

    // Fill the dp
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = m - 2; j >= 0; j--)
        {
            if (grid[i][j] == 1)
            {
                dp[i][j] = (dp[i + 1][j] + dp[i][j + 1]) % MOD;
            }
        }
    }
    return dp[0][0];
}
int uniquePathsMemo(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &memo)
{
    // MEMOIZATION APPROACH

    int MOD = 1000000007;

    int n = grid.size();
    int m = grid[0].size();

    // outof bound or unreachable
    if (i > n || j > m || grid[i][j] == 0)
    {
        return 0;
    }

    if (i == n - 1 || j == m - 1)
    {
        return 1;
    }

    if (memo[i][j] != -1)
    {
        return memo[i][j];
    }

    int rightPaths = uniquePathsMemo(i, j + 1, grid, memo) % MOD;
    int downPaths = uniquePathsMemo(i + 1, j, grid, memo) % MOD;

    memo[i][j] = (rightPaths + downPaths) % MOD;
    return memo[i][j];
}
int uniquePaths3(int n, int m, vector<vector<int>> &grid)
{
    vector<vector<int>> memo(n, vector<int>(m, -1));
    int result = uniquePathsMemo(0, 0, grid, memo);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << memo[i][j] << " ";
        }
        cout << endl;
    }
    return result;
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
// Coin Change
#include <iostream>
#include <vector>
using namespace std;
// N = 3, sum = 4
// coins = {1,2,3}
// Output: 4
// Explanation: Four Possible ways are: {1,1,1,1},{1,1,2},{2,2},{1,3}.
long long int count1(int coins[], int N, int sum)
{

    // code here.
    vector<vector<long long int>> dp(N + 1, vector<long long int>(sum + 1, 0));
    // sum = 0 case
    for (int i = 0; i <= N; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            // current coin cannot be used to make sum j
            if (coins[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
            }
        }
    }

    return dp[N][sum];
}
long long int coinChangeMemo(int coins[], int N, int sum, vector<vector<long long int>> &memo)
{
    if (sum == 0)
    {
        return 1;
    }
    if (N <= 0 || sum < 0)
    {
        return 0;
    }
    if (memo[N][sum] != -1)
    {
        return memo[N][sum];
    }

    // Count ways by including and excluding the coin at index N-1
    long long int includeCoin = coinChangeMemo(coins, N, sum - coins[N - 1], memo);
    long long int excludeCoin = coinChangeMemo(coins, N - 1, sum, memo);

    memo[N][sum] = includeCoin + excludeCoin;
    return memo[N][sum];
}
long long int count2(int coins[], int N, int sum)
{
    vector<vector<long long int>> memo(N + 1, vector<long long int>(sum + 1, -1));
    return coinChangeMemo(coins, N, sum, memo);
}
int main()
{
    int N, sum;
    cin >> N;
    cin >> sum;
    int *coins = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> coins[i];
    }
    long long int result1 = count1(coins, N, sum);
    cout << "Sol1 count is " << result1 << endl;
    long long int result2 = count2(coins, N, sum);
    cout << "Sol2 count is " << result2 << endl;
    return 0;
}
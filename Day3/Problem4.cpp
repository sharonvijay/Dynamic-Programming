#include <iostream>
#include <vector>
using namespace std;
// 0 - 1 Knapsack Problem
// Example 1:

// Input:
// N = 3
// W = 4
// values[] = {1,2,3}
// weight[] = {4,5,1}
// Output: 3
int knapSack(int W, int wt[], int val[], int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= W; w++)
        {
            // current weight greater than index w don't include
            if (wt[i - 1] > w)
            {
                dp[i][w] = dp[i - 1][w];
            }
            else
            {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - wt[i - 1]] + val[i - 1]);
            }
        }
    }
    return dp[n][W];
}
int main()
{
    int N;
    cin >> N;
    int *val = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> val[i];
    }

    int *wt = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> wt[i];
    }
    int W;
    cin >> W;
    int result = knapSack(W, wt, val, N);
    cout << "0-1 Knapsack " << result << endl;
    return 0;
}
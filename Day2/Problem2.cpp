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
            if (wt[i - 1] > w)
            {
                // if weight of current item is greater than sack size then don't include
                dp[i][w] = dp[i - 1][w];
            }
            else
            {
                // either include or exclude
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - wt[i - 1]] + val[i - 1]);
            }
        }
    }
    return dp[n][W];
}

int main()
{
    int W;
    cin >> W;
    int n;
    cin >> n;
    int *wt = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    int *val = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    int result = knapSack(W, wt, val, n);
    cout << "Sol 0-1 KnapSack " << result;
    return 0;
}
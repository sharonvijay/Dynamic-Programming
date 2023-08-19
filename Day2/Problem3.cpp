#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
// Minimum number of Coins
// Given an infinite supply of each
// denomination of Indian currency
// { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 }
// and a target value N.
// Find the minimum number of coins
// and/or notes needed to make the
// change for Rs N. You must return
// the list containing the value of coins required.

// Example 1:

// Input: N = 43
// Output: 20 20 2 1
// Explaination:
// Minimum number of coins and notes needed
// to make 43.
unordered_map<int, vector<int>> memo;

vector<int> minPartition1(int N)
{
    vector<int> denominations = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    if (N == 0)
    {
        return {};
    }
    if (memo.find(N) != memo.end())
    {
        return memo[N];
    }
    vector<int> result;

    for (int coin : denominations)
    {
        if (coin <= N)
        {
            vector<int> current = minPartition1(N - coin);
            if (result.empty() || current.size() + 1 < result.size())
            {
                result = current;
                result.push_back(coin);
            }
        }
    }
    memo[N] = result;
    return memo[N];
}
vector<int> minPartition2(int N)
{
    vector<int> denominations = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    vector<int> dp(N + 1, N + 1); // Initialize with a value greater than N
    dp[0] = 0;

    for (int i = 1; i <= N; ++i)
    {
        for (int coin : denominations)
        {
            if (coin <= i)
            {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    // Reconstruct the coins used
    vector<int> coinsUsed;
    int remaining = N;
    while (remaining > 0)
    {
        for (int coin : denominations)
        {
            if (coin <= remaining && dp[remaining - coin] + 1 == dp[remaining])
            {
                coinsUsed.push_back(coin);
                remaining -= coin;
                break;
            }
        }
    }
    reverse(coinsUsed.begin(), coinsUsed.end());
    return coinsUsed;
}
int main()
{
    int N;
    cin >> N;
    vector<int> result1 = minPartition1(N);
    cout << "Sol 1 Minimum no of coins required " << endl;
    for (auto r : result1)
    {
        cout << r << " ";
    }
    cout << endl;
    vector<int> result2 = minPartition2(N);
    cout << "Sol 2 Minimum no of coins required " << endl;
    for (auto r : result2)
    {
        cout << r << " ";
    }
    cout << endl;
    return 0;
}

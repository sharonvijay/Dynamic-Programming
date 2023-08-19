#include <iostream>
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

vector<int> minPartition(int N)
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
            vector<int> current = minPartition(N - coin);
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
int main()
{
    int N;
    cin >> N;
    vector<int> result = minPartition(N);
    cout << "Minimum no of coins required " << endl;
    for (auto r : result)
    {
        cout << r << " ";
    }
    cout << endl;
    return 0;
}

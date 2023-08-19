#include <iostream>
#include <vector>
using namespace std;

// Rod Cutting
// Given a rod of length N inches and an array of prices,
// price[]. price[i] denotes the value of a piece of length i.
// Determine the maximum value obtainable by
// cutting up the rod and selling the pieces.

// Note: Consider 1-based indexing.

// Example 1:

// Input:
// N = 8
// Price[] = {1, 5, 8, 9, 10, 17, 17, 20}
// Output:
// 22
// Explanation:
// The maximum obtainable value is 22 by
// cutting in two pieces of lengths 2 and
// 6, i.e., 5+17=22.
int cutRod1(int price[], int n)
{
    // RECURSIVE APPROACH

    // BASE CASE
    if (n <= 0)
    {
        return 0;
    }

    int maxVal = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        maxVal = max(maxVal, price[i - 1] + cutRod1(price, n - i));
    }
    return maxVal;
}
int cutRod2(int price[], int n)
{
    // MEMOISATION APPROACH
    int *dp = new int[n + 1];
    // BASE CASE
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int maxVal = INT_MIN;
        for (int j = 1; j <= i; j++)
        {
            maxVal = max(maxVal, price[j - 1] + dp[i - j]);
        }
        dp[i] = maxVal;
    }
    return dp[n];
}
int main()
{
    int n;
    cin >> n;
    int *price = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }
    int result1 = cutRod1(price, n);
    cout << "Sol1 max value is " << result1 << endl;
    int result2 = cutRod2(price, n);
    cout << "Sol2 max value is " << result2 << endl;
}
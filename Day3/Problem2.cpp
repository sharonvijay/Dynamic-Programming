#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Longest Increasing Subsequence
// Given an array of integers, find the length of the longest
// (strictly) increasing subsequence from the given array.

// Example 1:

// Input:
// N = 16
// A = {0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15}
// Output:
// 6
int longestSubsequence(int n, int a[])
{
    // Dynamic Programming Approach
    // To store the length for each element
    vector<int> dp(n, 1);

    for (int i = 1; i < n; i++)
    { // Start from index 1
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int result = longestSubsequence(n, a);
    cout << "The size is " << result << endl;
    return 0;
}
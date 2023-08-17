#include <iostream>
#include <vector>
using namespace std;

// Longest Increasing Subsequence
// Given an array of integers, find the length of the
// longest (strictly) increasing subsequence from the given array.

// Example 1:

// Input:
// N = 16
// A = {0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15}
// Output:
// 6
// Explanation:
// There are more than one LIS in this array. One such Longest
// increasing subsequence is {0,2,6,9,13,15}.
int longestSubsequence1(int n, int a[])
{
    // Dynamic Programming Approach
    // To store the length for each element
    vector<int> dp(n, 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (dp[j] < dp[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}
int longestSubsequence2(int n, int a[])
{
    vector<int> temp;
    temp.push_back(a[0]);
    for (int i = 1; i < n; i++)
    {
        if (a[i] > temp.back())
        {
            temp.push_back(a[i]);
        }
        else
        {
            int ind = lower_bound(temp.begin(), temp.end(), a[i]) - temp.begin();
            temp[ind] = a[i];
        }
    }
    return temp.size();
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
    int result1 = longestSubsequence1(n, a);
    cout << "Sol1 max length is " << result1 << endl;
    int result2 = longestSubsequence2(n, a);
    cout << "Sol2 max length is " << result2 << endl;
    return 0;
}
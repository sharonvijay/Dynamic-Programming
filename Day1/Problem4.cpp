#include <iostream>
#include <vector>
using namespace std;

// Kadane's Algorithm
// Given an array Arr[] of N integers.
// Find the contiguous sub-array(containing at least one number)
// which has the maximum sum and return its sum.

// Example 1:

// Input:
// N = 5
// Arr[] = {1,2,3,-2,5}
// Output:
// 9
// Explanation:
// Max subarray sum is 9
// of elements (1, 2, 3, -2, 5) which
// is a contiguous subarray.
long long maxSubarraySum(int arr[], int n)
{
    int currSum = 0;
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        maxSum = max(maxSum, currSum);
        // To Stop from making the currSum negative
        currSum = max(0, currSum);
    }

    return maxSum;
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    long long result = maxSubarraySum(arr, n);
    cout << "Sol max subarray sum is " << result << endl;
    return 0;
}
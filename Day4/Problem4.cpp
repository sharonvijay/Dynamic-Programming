#include <iostream>
#include <vector>
using namespace std;
// Maximum Sub Array
// Example 1:

// Input:
// n = 3
// a[] = {1, 2, 3}
// Output: 1 2 3
// Explanation: In the given array every
// element is non-negative.
vector<int> findSubarray(int a[], int n)
{
    long long max_sum = 0, curr_sum = 0;
    int max_len = 0, curr_len = 0;
    int max_start = -1, curr_start = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 0)
        {
            curr_sum += a[i];
            curr_len++;

            if (curr_sum > max_sum || (curr_sum == max_sum && curr_len > max_len))
            {
                max_sum = curr_sum;
                max_len = curr_len;
                max_start = curr_start;
            }
        }
        else
        {
            curr_sum = 0;
            curr_len = 0;
            curr_start = i + 1;
        }
    }

    vector<int> result;

    for (int i = max_start; i < max_start + max_len; i++)
    {
        result.push_back(a[i]);
    }
    return result;
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
    vector<int> result = findSubarray(a, n);
    vector<int>::iterator it;
    cout << "The subarray with maximum sum is ";
    for (it = result.begin(); it != result.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
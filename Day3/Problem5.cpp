#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Subset Sums
// Given a list arr of N integers,
// print sums of all subsets in it.

// Example 1:

// Input:
// N = 2
// arr[] = {2, 3}
// Output:
// 0 2 3 5
void generateSubsetSums(vector<int> &arr, int index, int currSum, vector<int> &sums)
{
    // BASE CASE
    if (index == arr.size())
    {
        sums.push_back(currSum);
        return;
    }

    // include current element
    generateSubsetSums(arr, index + 1, currSum + arr[index], sums);

    // exclude current element
    generateSubsetSums(arr, index + 1, currSum, sums);
}
vector<int> subsetSums(vector<int> arr, int N)
{
    vector<int> sums;
    generateSubsetSums(arr, 0, 0, sums);
    reverse(sums.begin(), sums.end());
    return sums;
}
int main()
{
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    vector<int> sums = subsetSums(arr, N);

    for (int sum : sums)
        cout << sum << " ";

    return 0;
}
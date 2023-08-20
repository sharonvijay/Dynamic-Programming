#include <iostream>
#include <vector>
using namespace std;
// Matrix Chain Multiplication
// Input: N = 4
// arr = {10, 30, 5, 60}
// Output: 4500
vector<vector<int>> memo;
int matrixChainMultiplication(int i, int j, vector<int> &arr)
{
    if (i == j)
    {
        return 0;
    }
    if (memo[i][j] != -1)
    {
        return memo[i][j];
    }
    memo[i][j] = INT_MAX;

    for (int k = i; k < j; ++k)
    {
        int cost = matrixChainMultiplication(i, k, arr) +
                   matrixChainMultiplication(k + 1, j, arr) +
                   arr[i - 1] * arr[k] * arr[j];
        memo[i][j] = min(memo[i][j], cost);
    }

    return memo[i][j];
}
int matrixMultiplication(int N, vector<int> &arr)
{
    memo.assign(N, vector<int>(N, -1));
    return matrixChainMultiplication(1, N - 1, arr);
}
int main()
{
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    int result = matrixMultiplication(N, arr);
    cout << "Solution " << result;
    return 0;
}
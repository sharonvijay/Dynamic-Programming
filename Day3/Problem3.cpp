#include <iostream>
#include <vector>
using namespace std;
// Count ways to reach the n'th stair

// Input:
// n = 4
// Output: 5
int countWays1(int n)
{
    const int MOD = 1000000007;
    if (n <= 1)
    {
        return n;
    }
    int a = 1, b = 1, c;
    for (int i = 2; i <= n; i++)
    {
        c = (a + b) % MOD;
        a = b;
        b = c;
    }
    return b;
}
int countWays2(int n)
{
    const int MOD = 1000000007;
    vector<int> dp(n, 0);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }
    return dp[n];
}
int main()
{
    int n;
    cin >> n;
    int result1 = countWays1(n);
    cout << "Sol1 is " << result1 << endl;
    int result2 = countWays2(n);
    cout << "Sol2 is " << result2 << endl;
    return 0;
}
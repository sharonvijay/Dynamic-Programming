#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_set>
using namespace std;
// Fibonacci in the array
// Given an array arr of size N, the task is to count
// the number of elements of the array which are Fibonacci numbers

// Example 1:

// Input: N = 9, arr[] = {4, 2, 8, 5, 20, 1,
//                               40, 13, 23}
// Output: 5
// Explanation: Here, Fibonacci series will
// be 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55.
// Numbers that are present in array are
// 2, 8, 5, 1, 13
int checkFib1(long long arr[], int N)
{
    // Your code goes here
    const int MAX = 100000;
    vector<bool> isFib(MAX, false);

    long long a = 0, b = 1;

    while (b < MAX)
    {
        isFib[b] = true;
        long long next = a + b;
        a = b;
        b = next;
    }

    int countFib = 0;
    for (int i = 0; i < N; i++)
    {
        if (isFib[arr[i]])
        {
            countFib++;
        }
    }

    return countFib;
}
int checkFib2(long long arr[], int N)
{
    // Your code goes here
    unordered_set<long long> fibNumbers;

    long long a = 0, b = 1;

    while (b <= 1e18)
    {
        long long result = a + b;
        fibNumbers.insert(result);
        a = b;
        b = result;
    }

    int countFib = 0;
    for (int i = 0; i < N; i++)
    {
        if (fibNumbers.find(arr[i]) != fibNumbers.end())
        {
            countFib++;
        }
    }
    return countFib;
}
bool isPerfectSquare(long long int x)
{
    long long int s = sqrt(x);
    return (s * s == x);
}

bool isFib(long long n)
{
    return (isPerfectSquare(pow((long long int)n, 2) * 5 + 4)) || (isPerfectSquare(pow((long long int)n, 2) * 5 - 4));
}

int checkFib3(long long a[], int n)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (isFib(a[i]))
        {
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    int N;
    cin >> N;
    long long *arr = new long long[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    int result1 = checkFib1(arr, N);
    cout << "Sol1 ans is " << result1 << endl;
    int result2 = checkFib2(arr, N);
    cout << "Sol2 ans is " << result2 << endl;
    int result3 = checkFib3(arr, N);
    cout << "Sol2 ans is " << result3 << endl;
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int fibo(int n, vector<int> &dp)
{
    // if (n <= 1)
    // {
    //     return n;
    // }
    // if (dp[n] != -1)
    // {
    //     return dp[n];
    // }

    // return dp[n] = fibo(n-1,dp)+fibo(n-2,dp);

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;
    cout << fibo(n, dp) << endl;

    int prev = 1;
    int prev2 = 1;
    int curr_i;
    for (int i = 2; i <= n; i++)
    {
        curr_i = prev + prev2;
        prev = prev2;
        prev = curr_i;
    }
    cout << prev << endl;
}
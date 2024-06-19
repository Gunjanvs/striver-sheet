#include <iostream>
using namespace std;

int f(int m, int n, vector<vector<int>> &dp)
{
    if (m == 0 && n == 0)
    {
        return 1;
    }
    if (m < 0 || n < 0)
    {
        return 0;
    }
    if (dp[m][n] != -1)
    {
        return dp[m][n];
    }

    int up = f(m - 1, n, dp);
    int left = f(m, n - 1, dp);
    return dp[m][n] = up + left;
}
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    // return f(m-1,n-1,dp);
    dp[0][0] = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // write the recurrence relation
            if (i == 0 && j == 0)
                dp[0][0] = 1;
            else
            {
                int up = 0, left = 0;
                if (i > 0)
                    up = dp[i - 1][j];
                if (j > 0)
                    left = dp[i][j - 1];
                dp[i][j] = up + left;
            }
        }
    }
    return dp[m - 1][n - 1];
}

int main()
{
    int n;
    int m;
    vector<int> dp(n, 0);
    for (int i = 0; i < m; i++)
    {
        vector<int> temp(n, 0);
        for (int j = 0; j < n; j++)
        {
            // har row ka nikalo

            if (i == 0 && j == 0)
                temp[j] = 1;
            else
            {
                int up = 0, left = 0;
                if (i > 0)
                    up = dp[j];
                if (j > 0)
                    left = temp[j - 1];
                temp[j] = up + left;
            }
        }
        dp = temp;
    }
    return dp[n - 1];
}
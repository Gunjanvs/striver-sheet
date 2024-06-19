#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int f(int i, int j, int n, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{

    if (j < 0 || j >= n)
        return 1e9;
    if (i == 0)
        return matrix[i][j];

    if (dp[i][j] != INT_MIN)
        return dp[i][j];
    int str = matrix[i][j] + f(i - 1, j, n, matrix, dp);
    int rd = matrix[i][j] + f(i - 1, j + 1, n, matrix, dp);
    int ld = matrix[i][j] + f(i - 1, j - 1, n, matrix, dp);
    return dp[i][j] = min(str, min(rd, ld));
}
int f2(vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    // use the base cases
    // when i =0 posiible values of j
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 0; i < matrix[0].size(); ++i)
    {
        dp[0][i] = matrix[0][i];
    }

    for (int i = 1; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            int up = matrix[i][j] + dp[i - 1][j];
            int dl = matrix[i][j];
            if (j - 1 >= 0)
            {
                dl += dp[i - 1][j - 1];
            }
            else
            {
                dl = 1e9;
            }
            int dr = matrix[i][j];

            if (j + 1 < n)
            {
                dr += dp[i - 1][j + 1];
            }
            else
            {
                dr = 1e9;
            }
            dp[i][j] = min(up, min(dr, dl));
        }
    }
    int maxi = dp[m - 1][0];
    for (int i = 1; i < n; ++i)
    {
        maxi = min(dp[m - 1][i], maxi);
    }
    return maxi;
}
int minFallingPathSum(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    // int ans=INT_MAX;
    // vector<vector<int>> dp(m,vector<int> (n,0));

    // return f2(matrix,dp);
    vector<int> prev(n, 0);
    vector<int> curr(n, 0);
    for (int j = 0; j < n; j++)
    {
        prev[j] = matrix[0][j];
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int up = matrix[i][j] + prev[j];
            int dl = matrix[i][j];
            if (j - 1 >= 0)
                dl += prev[j - 1];
            else
                dl = 1e9;
            int dr = matrix[i][j];
            if (j + 1 < n)
                dr += prev[j + 1];
            else
                dr = 1e9;

            curr[j] = min(up, min(dl, dr));
        }
        prev = curr;
    }
    int maxi = prev[0];
    for (int i = 1; i < n; ++i)
    {
        maxi = min(prev[i], maxi);
    }
    return maxi;
}
int main()
{
}
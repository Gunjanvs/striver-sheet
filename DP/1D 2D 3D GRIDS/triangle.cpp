#include <iostream>
using namespace std;

int f(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp, int n)
{
    if (i == n - 1)
    {
        return triangle[i][j];
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int down = f(i + 1, j, triangle, dp, n) + triangle[i][j];
    int diag = f(i + 1, j + 1, triangle, dp, n) + triangle[i][j];
    return dp[i][j] = min(down, diag);
}

int f2(int i,int j,vector<vector<int>>&dp,vector<vector<int>> &triangle,int n){
    // reduce the stack space 

    for (int j = 0; j < n; j++)
    {
        dp[n-1][j] = triangle[n-1][j];
    }

    for (int i = n-2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            // 
            int d = dp[i+1][j] + triangle[i+1][j];
            int dg = dp[i+1][j+1] + triangle[i+1][j+1];
            dp[i][j] = min(d,dg);
        }
        
    }
    return dp[0][0];
    
    
}

int main()
{
}

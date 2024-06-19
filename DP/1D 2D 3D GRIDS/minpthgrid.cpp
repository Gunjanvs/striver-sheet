// minpthgrid.cpp
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

typedef long long ll;
// typedef 1e9 l; 
    ll f(ll i,ll j,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(i==0 &&j ==0){
            return grid[0][0];
        }
        if(i < 0 || j < 0){
            return 1e9;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        ll up = f(i-1,j,grid,dp) + grid[i][j];
        ll left =f(i,j-1,grid,dp) + grid[i][j];
        return dp[i][j]=min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
    	int m = grid.size();
    	int n =grid[0].size();
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        // return f(grid.size()-1,grid[0].size()-1,grid,dp);

        // tabulation part 

        for (int i = 0; i < m; ++i)
        {

        	for (int j = 0; j < n; ++j)
        	{
        		if (i ==0 && j==0)
        		{
        			dp[0][0] = grid[0][0];
        		}
        		else{
        			int up =grid[i][j],left =grid[i][j];
        			// requiring the prev rows and curr col 
        			if(i > 0) up += dp[i-1][j];
        			else up += 1e9;
        			// requiring curr row prev col
        			if(j > 0) left += dp[i][j-1];
        			else left += 1e9;
        			dp[i][j] = min(up,left);
        		}
        	}
        }
        return dp[m-1][n-1];

        for (int i = 0; i < m; ++i)
        {
        	// this loop will be over when i = n
        	vector<int> prev(m,0);
        	for (int j = 0; j < n; ++j)
        	{
        		vector<int> curr(n,0);
        		if (i ==0 && j==0)
        		{
        			curr[j] = grid[i][j];
        		}
        		else{
        			int up =grid[i][j],left =grid[i][j];
        			// requiring the prev rows and curr col 
        			if(i > 0) up += prev[j];
        			else up += 1e9;
        			// requiring curr row prev col
        			if(j > 0) left += curr[j-1];
        			else left += 1e9;
        			curr[j] = min(up,left);
        		}
        	}
        	prev = curr;
        }
        return prev[m-1];
    }

int main(){

}
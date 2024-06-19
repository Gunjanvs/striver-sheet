// cherryPickupII.cpp
#include <vector>
#include <algorithm>

using namespace std;

    int solve(int i, int j1, int j2, int m, int n, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        if (j1 < 0 || j1 >= n || j2 < 0 || j2 >= n) {
            return -1e9;
        }
        if (i == m - 1) {
            if (j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        if (dp[i][j1][j2] != -1) {
            return dp[i][j1][j2];
        }
        int maxi = -1e9;
        for (int d1 = -1; d1 <= 1; d1++) {
            for (int d2 = -1; d2 <= 1; d2++) { // Fixed loop condition
                int value = 0;
                if (j1==j2) value = grid[i][j1];
                else value = grid[i][j1] + grid[i][j2];
                value += solve(i + 1, j1+d1, j2+d2, m, n, grid, dp);
                maxi = max(maxi, value);
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        // int m = grid.size();
        // int n = grid[0].size();
        // vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1))); // Fixed dimensions
        // return solve(0, 0, n - 1, m, n, grid, dp);

    	int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, 0)));

        // Initialize dp for the last row
        for (int j1 = 0; j1 < n; ++j1) {
            for (int j2 = 0; j2 < n; ++j2) {
                dp[m - 1][j1][j2] = (j1 == j2) ? grid[m - 1][j1] : grid[m - 1][j1] + grid[m - 1][j2];
            }
        }

        for (int i = m - 2; i >= 0; --i) {
            for (int j1 = 0; j1 < n; ++j1) {
                for (int j2 = 0; j2 < n; ++j2) {
                    int maxi = -1e9;
                    for (int d1 = -1; d1 <= 1; ++d1) {
                        for (int d2 = -1; d2 <= 1; ++d2) {
                            if (j1 + d1 < n && j2 + d2 < n && j1 + d1 >= 0 && j2 + d2 >= 0) {
                                int value = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
                                value += dp[i + 1][j1 + d1][j2 + d2];
                                maxi = max(maxi, value);
                            }
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }
        return dp[0][0][n - 1];
     }


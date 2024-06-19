#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Solution
{
public:
    int f(int ind, int prev_ind, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (ind == nums.size())
            return 0;
        if (dp[ind][prev_ind + 1] != -1)
            return dp[ind][prev_ind + 1];
        int len;
        len = f(ind + 1, prev_ind, nums, dp);
        if (prev_ind == -1 || nums[ind] > nums[prev_ind])
        {
            len = max(len, 1 + f(ind + 1, ind, nums, dp));
        }
        return dp[ind][prev_ind + 1] = len;
    }
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        // vector<vector<int>> dp(n, vector<int>(n + 1, 0));
        // return f(0,-1,nums,dp);

        // tabulations part
        // for (int ind = n - 1; ind >= 0; ind--)
        // {
        //     for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--)
        //     {
        //         int len;
        //         len = dp[ind + 1][prev_ind + 1];
        //         if (prev_ind == -1 || nums[ind] > nums[prev_ind])
        //         {
        //             len = max(len, 1 + dp[ind + 1][ind + 1]);
        //         }
        //         dp[ind][prev_ind + 1] = len;
        //     }
        // }
        // return dp[0][-1 + 1];

        // space optimise it
        vector<int> next(n + 1, 0);
        vector<int> cur(n + 1, 0);
        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--)
            {
                int len;
                len = next[prev_ind + 1];
                if (prev_ind == -1 || nums[ind] > nums[prev_ind])
                {
                    len = max(len, 1 + next[ind + 1]);
                }
                cur[prev_ind + 1] = len;
            }
            next = cur;
        }
        return cur[-1 + 1];

        // dp[i] stores the index max sequence length to that index
        int maxi = 1;
        vector<int> dp(n + 1, 0);
        for (int ind = 0; ind < n; ind++)
        {
            for (int prev = 0; prev < ind; prev++)
            {
                if (nums[ind] < nums[prev])
                {
                    dp[ind] = max(dp[ind], 1 + dp[prev]);
                }
            }
            maxi = max(maxi, dp[ind]);
        }
        return maxi;



        // print 
    }
};
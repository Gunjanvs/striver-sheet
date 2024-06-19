#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Solution
{
public:
   
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        // dp[i] stores the index max sequence length to that index
        int maxi = 1,last_index =0;
        vector<int> dp(n + 1, 0),hash(n+1,0);
        for (int ind = 0; ind < n; ind++)
        {
            hash[ind]=ind;
            for (int prev = 0; prev < ind; prev++)
            {
                if (nums[ind] < nums[prev] && dp[ind] < 1 + dp[prev])
                {
                    dp[ind] = 1 + dp[prev];
                    hash[ind] = prev;
                }
            }
            if (dp[ind] > maxi)
            {
                maxi = dp[ind];
                last_index = ind;
            }
            
        }
        while (hash[last_index]!=last_index)
        {
            /* code */
        }
        
        return maxi;
    }
};
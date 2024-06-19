#include<iostream>
#include<vector>
using namespace std ;
class Solution {
public:

    int findNumberOfLIS(vector<int>& nums) {
        int n =nums.size();
        int maxi =0 ;
        vector<int>dp(n+1,1);
        vector<int>cnt(n+1,1);
        int maxi =1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i] && dp[j]+1> dp[i])
                {
                    dp[i]=dp[j]+1;
                    cnt[i]=cnt[j];
                }
                else if (nums[j] < nums[i] && dp[j]+1 == dp[i])
                {
                    cnt[i]+=cnt[j];
                }
            }
            if (cnt[i] > maxi)
            {
                maxi = cnt[i];
            }
            
        }
        return maxi;
    }
};
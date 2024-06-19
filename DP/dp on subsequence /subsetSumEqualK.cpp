// subsetSumEqualK.cpp
#include<iostream>
#include<vector>
using namespace std;
class Solution{   
public:
    bool f(int i,int target,vector<int> &nums,vector<vector<int>>&dp){
        if(target == 0)return true;
        if(i == 0) return (nums[i] == target);
        if(dp[i][target]!=-1)return dp[i][target];
        bool ntake = f(i-1,target,nums,dp);
        bool take = false;
        if(target >= nums[i]) take = f(i-1,target-nums[i],nums,dp);
        
        return dp[i][target] = (ntake || take);
    }
    bool isSubsetSum(vector<int>nums, int sum){
        // vector<vector<int> >dp(101,vector<int> (10001,-1));
        // return f(arr.size()-1,sum,arr,dp);

        // target = 0 possible value of i 
        int n = nums.size();
        vector<vector<bool> >dp(n,vector<bool> (sum+1,0));

        for (int i = 0; i < n; ++i)
        {
        	dp[i][0]= true;
        }
        	
        dp[0][nums[0]] = true;

        for (int i = 1; i < n; ++i)
        {
        	for (int target = 1; target <=sum; ++target)
        	{
        		bool ntake = dp[i-1][target];
		        bool take = false;
		        if(target >= nums[i]) take = dp[i-1][target-nums[i]];
		        
		        dp[i][target] = (ntake || take);
        	}
        }
        return dp[n-1][sum];
    }
    bool f3(vector<int>nums, int sum){
    	int n = nums.size();
    	vector<bool> prev(sum+1,0),curr(sum+1,0);
    	prev[0] =curr[0] = true;
    	prev[nums[0]] = true;
for (int i = 1; i < n; ++i)
        {
        	for (int target = 1; target <=sum; ++target)
        	{
        		bool ntake = prev[target];
		        bool take = false;
		        if(target >= nums[i]) take = prev[target-nums[i]];
		        
		        curr[target] = (ntake || take);
        	}
        	prev = curr;
        }
        return prev[sum];
    }

};
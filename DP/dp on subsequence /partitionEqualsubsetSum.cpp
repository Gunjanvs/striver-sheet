// partitionEqualsubsetSum.cpp
#include<iostream>
#include<vector>
using namespace std;

bool f(int index,int target,vector<int>&nums){
	if(target == 0){
		return true;
	}
	if(index == 0)return nums[index] == target;
	bool ntake = f(index-1,target,nums);
	bool take = false;
	if(nums[index] <=target)take = f(index-1,target-nums[index],nums);
	return take||ntake;
}
bool canPartition(vector<int>& nums) {
	int n = nums.size();
	// int target=1;
	int sum =0;
	for(int i=0;i<n;i++){
		sum+= nums[i];
	}
	int target = sum/2;
	return f(0,target,nums);


	// target = 0 ; index = ? 0 --- n
	vector<vector<int>> dp(n,vector<int>(target+1,0));
	for(int i =0; i< n;i++){
		dp[i][0] = true;
	}
	dp[0][nums[0]] = true;
	for (int index = 1; index < n; ++index)
	{
		for (int i = 1; i <= target; ++i)
		{
			bool ntake = dp[index-1][target];
			bool take = dp[index-1][target-nums[i]];
			dp[index][i] = take+ ntake;
		}
	}
	return dp[n-1][target];
}
int f(int index,int target,vector<int>&nums){
	// if(target == 0){
	// 	return true;
	// }
	// if(index == 0)return nums[index] == target;
	if(index == 0){
		if(sum == 0 && nums[0] = 0)return 2;
		if(sum == 0 || sum == nums[0])return 1;
	}
	bool ntake = f(index-1,target,nums);
	bool take = 0;
	if(nums[index] <=target)take = f(index-1,target-nums[index],nums);
	return take+ntake;
}
bool canPartition(vector<int>& nums) {
	int n = nums.size();
	// int target=1;
	int sum =0;
	for(int i=0;i<n;i++){
		sum+= nums[i];
	}
	int target = sum/2;
	return f(0,target,nums);


	// target = 0 ; index = ? 0 --- n
	vector<vector<int>> dp(n,vector<int>(target+1,0));
	for(int i =0; i< n;i++){
		dp[i][0] = true;
	}
	dp[0][nums[0]] = true;
	for (int index = 1; index < n; ++index)
	{
		for (int i = 1; i <= target; ++i)
		{
			bool ntake = dp[index-1][target];
			bool take = dp[index-1][target-nums[i]];
			dp[index][i] = take+ ntake;
		}
	}
	return dp[n-1][target];
}


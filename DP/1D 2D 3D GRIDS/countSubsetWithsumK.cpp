// countSubsetWithsumK.cpp
#include<bits/stdc++.h>
using namespace std ; 
const int MOD = 1000000007;
int ans(int i,vector<int> &a,int k,vector<vector<int>> &dp){
	if(k == 0)return 1;
	if(i == 0){
		return (a[i] == k)?1:0;
	}
	if(dp[i][k] != -1)return dp[i][k];
	int take = 0 ;
	if(a[i] <= k)take = (ans(i-1,a,k-a[i],dp))%MOD;
	int ntake = (ans(i-1,a,k,dp))%MOD;
	return dp[i][k] =  (take+ntake)%MOD;
}
int findWays(vector<int>& arr, int k)
{
	
	int n = arr.size();
	// vector<vector<int> >dp(n,-1)
	vector<vector<int>> dp(n, vector<int>(k+1, -1));
	return ans(n-1,arr,k,dp);
}
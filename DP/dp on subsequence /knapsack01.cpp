// knapsack01.cpp
#include<iostream>
#include<vector>
using namespace std ;

class solution{
public:
	int f(int i,vector<int> wt, vector<int> value,int n,int w,vector<vector<int>>&dp){
		if(i == 0){
			if(wt[i] <= w)return value[i];
			else return 0;
		}
		if(dp[i][w]!=-1)return dp[i][w];
		int npick = f(i-1,wt,value,n,w,dp);
		int pick = INT_MIN;
		if(wt[i] <= w)pick =value[i] +f(i-1,wt,value,n,w-wt[i],dp);
		return dp[i][w]=max(pick,npick);
	}
	int knapsack(vector<int>wt,vector<int> value,int n,int W){
		vector<vector<int>>dp(n,vector<int>(W+1,-1));
		// return f(n-1,wt,value,n,W,dp);
		
	}
};
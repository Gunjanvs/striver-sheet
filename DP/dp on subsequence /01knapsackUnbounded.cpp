// 01knapsackUnbounded.cpp
#include<iostream>
#include<vector>
using namespace std ;

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int i,int values[],int wt[],int w,vector<vector<int>>&dp){
	if(i == 0){
	    return (w/wt[0])*values[i];
	}
	
// 	if(w ==0)return 0;
	if(dp[i][w] !=-1)return dp[i][w];
	int npick = f(i-1,values,wt,w,dp);
	int pick = INT_MIN;
	if(wt[i] <= w) pick = f(i,values,wt,w-wt[i],dp) +values[i];
	return dp[i][w] = max(pick,npick);
}
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp(N,vector<int>(W+1,-1));
        // return f(N-1,val,wt,W,dp);
        for(int i =0 ;i <=W;i++){
            dp[0][i] =(i/wt[0])*val[0] ;
        }
        for(int i = 1;i<N;i++){
            for(int weight = 0 ; weight <=W;weight++){
                int npick = dp[i-1][weight];
                int pick =0;
                if(wt[i] <= weight)pick =val[i] +dp[i][weight-wt[i]];
                dp[i][weight] = max(pick,npick);
            }
        }
        return dp[N-1][W];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int i,int values[],int wt[],int w,vector<vector<int>>&dp){
	if(i == 0){
	    return (w/wt[0])*values[i];
	}
	
// 	if(w ==0)return 0;
	if(dp[i][w] !=-1)return dp[i][w];
	int npick = f(i-1,values,wt,w,dp);
	int pick = INT_MIN;
	if(wt[i] <= w) pick = f(i,values,wt,w-wt[i],dp) +values[i];
	return dp[i][w] = max(pick,npick);
}
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp(N,vector<int>(W+1,-1));
        // return f(N-1,val,wt,W,dp);
        for(int i =0 ;i <=W;i++){
            dp[0][i] =(i/wt[0])*val[0] ;
        }
        for(int i = 1;i<N;i++){
            for(int weight = 0 ; weight <=W;weight++){
                int npick = dp[i-1][weight];
                int pick =0;
                if(wt[i] <= weight)pick =val[i] +dp[i][weight-wt[i]];
                dp[i][weight] = max(pick,npick);
            }
        }
        return dp[N-1][W];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends
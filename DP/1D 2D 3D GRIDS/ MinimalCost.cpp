#include<iostream>
using namespace std ;

int minimizeCost(int index,int n, int k, vector<int> &height){

    if (index == 0)
    {
        return 0;
    }
    
    int min_steps =INT_MAX;
    for (int j = 1; j <=k; j++)
    {
        // need to take of index 
        if (index-j >= 0)
        {
            int jump = minimizeCost(index-j,n,k,height) + abs(height[index]-height[index-j]);
            min_steps=min(min_steps,jump);
        }
        
    }
    return min_steps;
}
// #include<bits/stdc++.h>
int solver(int index ,vector<int>&dp,vector<int>&height,int k){
    if(index == 0){
        return 0;
    }
    if(dp[index]!=-1){
        return dp[index];
    }

    int min_steps = INT_MAX;
    // int jump =INT_MAX;
    for(int i=1;i<=k;i++){
        if(index-i >=0){
           int jump = solver(index-i,dp,height,k) + abs(height[index-i]-height[index]);
           min_steps=min(min_steps,jump);
           dp[index] = min_steps;
        }
        
    }
    return min_steps;
}
int main(){

}
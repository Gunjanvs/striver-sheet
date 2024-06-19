//
//  main.cpp
//  robberHouse.cpp
//
//  Created by Gunjan Vidya Sagar on 21/02/24.
//

#include<iostream>
#include<vector>
using namespace std;

int ans(int index ,vector<int> &dp,vector<int> &arr){
    if (index == 0) {
        return arr[index];
    }
    if (index < 0) {
        return 0;
    }
    if (dp[index]!=-1) {
        return dp[index];
    }
    
    int pick = arr[index] + ans(index-2,dp,arr);
    int non_pick = 0 + ans(index-1,dp,arr);
    return dp[index] = max(pick,non_pick);
}


int main(){
    vector<int> nums{2,1,4,9};
    vector<int> dp(nums.size()+1,-1);
    int index = nums.size( )-1;
    cout << ans(index,dp,nums) << endl;

    // L5 space optimisation 
    int prev_i =0;
    int prev2 =0 ;
    for (int i = 1; i < nums.size(); i++)
    {
        int take = nums[i];
        if (i > 1)
        {
            take += prev2;
        }
        int non = 0 + prev_i;
        int curr_i = max(take,non);
        prev2 =prev_i;
        prev_i = curr_i;
    }
    return prev_i;
}

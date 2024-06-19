#include<iostream>
using namespace std;

int cs(int n,vector<int> &dp){
    // if (n == 1)
    // {
    //     return 1;
    // }
    // if (n==0)
    // {
    //     return 1;
    // }
    
    // if (dp[n] != -1)
    // {
    //     return dp[n];
    // }

    // return dp[n] = cs(n-1,dp)+cs(n-2,dp);

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
    
}

int main(){
    int n ;
    cin >> n ;
    vector<int> dp(n+1,-1);
    dp[0]=1;
    dp[1]=1;
    cout << cs(n,dp)<<endl;

}
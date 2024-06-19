#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int f(int i, int prev, vector<int> &power, unordered_map<int, int> &mp,vector<vector<int>>&dp)
    {
        if (i == power.size())
            return 0;
        if(dp[i][prev]!=-1)return dp[i][prev];
        int take = 0;
        int ntake = f(i + 1, prev, power, mp,dp);

        if (prev == -1 || mp[power[i]]==0)
        {
            mp[power[i] - 2]++;
            mp[power[i] - 1]++;
            mp[power[i] + 2]++;
            mp[power[i] + 1]++;
            take = power[i] + f(i + 1,i, power, mp,dp);
            // Revert the changes to mp
            mp[power[i] - 2]--;
            mp[power[i] - 1]--;
            mp[power[i] + 2]--;
            mp[power[i] + 1]--;
    
        }
        return dp[i][prev]= max(take, ntake);
    }

    long long maximumTotalDamage(vector<int> &power)
    {
        int n =power.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        unordered_map<int, int> mp;
        return f(0, -1, power, mp,dp);
    }
};

// int main()
// {
//     Solution solution;
//     vector<int> power = {1, 3, 1, 5, 3};
//     cout << "Maximum Total Damage: " << solution.maximumTotalDamage(power) << endl;
//     return 0;
// }

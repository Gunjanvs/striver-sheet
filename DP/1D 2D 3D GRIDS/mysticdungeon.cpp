#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int f(int indx, vector<int> &energy, int k, vector<int> &dp)
    {
        if (indx >= energy.size())
            return 0;
        if (dp[indx] != -1)
            return dp[indx];
        int pick = energy[indx] + f(indx + k, energy, k, dp);
        return dp[indx] = pick;
    }
    int maximumEnergy(vector<int> &energy, int k)
    {
        int n = energy.size();
        int maxi = INT_MIN;
        vector<int> dp(n, -1);
        for (int i = 0; i < n; i++)
        {
            int ans = f(i, energy, k, dp);
            maxi = max(maxi, ans);
        }
        return maxi;
    }
};
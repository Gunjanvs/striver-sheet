#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int f(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
    {
        if (i > j)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int len = INT_MAX;
        for (int ind = i; ind <= j; ind++)
        {
            int cost = cuts[j + 1] - cuts[i - 1] + f(i, ind - 1, cuts,dp) + f(ind + 1, j, cuts,dp);
            len = min(len, cost);
            
        }
        return dp[i][j]=len;
    }
    int minCost(int n, vector<int> &cuts)
    {
        int c = cuts.size();
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
        return f(1, c, cuts, dp);
    }
};

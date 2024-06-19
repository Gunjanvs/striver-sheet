#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int f(int index, int buy, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (index == prices.size())
        {
            return 0;
        }
        if (dp[index][buy] != -1)
            return dp[index][buy];
        if (buy)
        {
            // sell it
            int bought = -prices[index] + f(index + 1, 0, prices, dp);
            int nbought = f(index + 1, 1, prices, dp);
            return dp[index][buy] = max(bought, nbought);
        }
        else
        {
            int sell = prices[index] + f(index + 2, 1, prices, dp);
            int nsell = f(index + 1, 0, prices, dp);
            return dp[index][buy] = max(nsell, sell);
        }
    }
    int maxProfit(vector<int> &prices)
    {
    }
};
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int ans = 0;
        int n = prices.size();
        int takefirst = prices[0];
        for (int i = 1; i < n; i++)
        {
            int diff = prices[i] - takefirst;
            if (diff > ans)
                ans = diff;
            if (diff < 0)
            {
                // means we got smallest one so update
                takefirst = prices[i];
            }
        }
        return ans;
    }
};
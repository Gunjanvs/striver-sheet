#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int n;
    int m;
    vector<vector<unordered_map<int, int>>> dp;
    int ans(vector<int> &nums, vector<int> &andvalue, int i, int j, int andOp)
    {
        if (i >= n)
        {
            if (j >= m)
            {
                return 0;
            }
            else
            {
                return 1e9;
            }
        }
        else if (j >= m)
        {
            return 1e9;
        }
        if (dp[i][j].count(andOp))
        {
            return dp[i][j][andOp];
        }
        int take_i = 1e9;
        if ((andOp & nums[i]) == andvalue[j])
        {
            take_i = nums[i] + ans(nums, andvalue, i + 1, j + 1, ((1 << 17) - 1));
        }
        int ntake_i = ans(nums, andvalue, i + 1, j, (andOp & nums[i]));
        return dp[i][j][andOp] = min(take_i, ntake_i);
    }
    int minimumValueSum(vector<int> &nums, vector<int> &andValues)
    {
        n = nums.size();
        m = andValues.size();
        dp.resize(n + 1, vector<unordered_map<int, int>>(11));
        int result = ans(nums, andValues, 0, 0, ((1 << 17) - 1));
        return (result == 1e9) ? -1 : result;
    }
};
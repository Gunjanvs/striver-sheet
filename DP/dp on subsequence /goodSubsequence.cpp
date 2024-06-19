#include <iostream>
#include <vector>
using namespace std;

#include <vector>
#include <algorithm>

class Solution
{
public:
    int f(int ind, int k, int prev, vector<int> &a, vector<vector<vector<int>>> &dp)
    {
        if (ind == -1)
        {
            // Base case: No elements left to process
            return 0;
        }

        if (dp[ind][k][prev + 1] != -1)
            return dp[ind][k][prev + 1];

        int notTake = f(ind - 1, k, prev, a, dp); // Skip the current element

        int take = 0;
        if (prev == -1 || a[ind] == a[prev])
        {
            // Include the current element without using a change
            take = 1 + f(ind - 1, k, ind, a, dp);
        }
        else if (k > 0)
        {
            // Include the current element using a change
            take = 1 + f(ind - 1, k - 1, ind, a, dp);
        }

        return dp[ind][k][prev + 1] = std::max(take, notTake);
    }

    int maximumLength(vector<int> &nums, int k)
    {
        int n = nums.size();
        // dp[ind][k][prev + 1]: using the first 'ind' elements, with 'k' changes allowed, previous element being 'prev'
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(n + 1, -1)));
        return f(n - 1, k, -1, nums, dp);
    }
};
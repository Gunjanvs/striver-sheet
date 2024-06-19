#include <iostream>
using namespace std;

// recursion solution
int solve(int index, vector<int> &heights)
{
    if (index == 0)
    {
        return 0;
    }
    int left = solve(index - 1, heights) + abs(heights[index] - heights[index - 1]);
    int right = INT_MAX;
    if (index > 1)
    {
        right = solve(index - 2, heights) + abs(heights[index - 2] - heights[index]);
    }

    return min(left, right);
}

// recursion to memo

int memo(int index, vector<int> &heights, vector<int> &dp)
{
    if (index == 0)
    {
        return 0;
    }

    if (dp[index] != -1)
    {
        return dp[index];
    }
    int left = memo(index - 1, heights, dp) + abs(heights[index - 1] - heights[index]);
    int right = INT_MAX;
    if (right > 1)
    {
        right = memo(index - 2, heights, dp) + abs(heights[index - 2] - heights[index]);
    }

    return dp[index] = min(left, right);
}

// tabulation bottom  up

int bottomUp(int index, int n, vector<int> &heights)
{
    vector<int> dp(n + 1, -1);
    // from base case
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int left = dp[i - 1] + abs(heights[i - 1] - heights[i]);
        int right = INT_MAX;
        if (right > 1)
        {
            right = dp[i - 2] + abs(heights[i - 2] - heights[i]);
        }

        dp[i] = min(left, right);
    }

    return dp[n-1];
}

// space optimization

int space(int n ,vector<int>&heights){
    int previ=0;
    int prev2=0;

    for (int i = 1; i < n; i++)
    {
        int fs = previ + abs(heights[i-1]-heights[i]);
        int ss = INT_MAX;
        if (i >1)
        {
            ss = prev2 + abs(heights[i-2]-heights[i]);
        }
        
        int current_i = min(fs,ss);
        prev2=previ;
        previ =current_i;
    }
    // n-1(prev) n(i)
    return previ;
}

int main()
{
    int n, index;
    cin >> n;

    vector<int> heights(n);

    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }
    cout << "enter index" << endl;
    cin >> index;
    vector<int> dp(n + 1, -1);
    cout << solve(index, heights) << endl;
    cout << memo(index, heights, dp);
}
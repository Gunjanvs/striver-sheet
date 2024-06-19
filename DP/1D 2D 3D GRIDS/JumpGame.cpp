#include <iostream>
#include <vector>
class Solution
{
public:
    int n;
    int t[10001];
    bool solver(int index, vector<int> &nums)
    {
        if (index >= n - 1)
        {
            return true;
        }
        if (t[index] != -1)
        {
            return t[index];
        }
        bool result = false;
        if (nums[index] > 0)
        {
            for (int i = nums[index]; i > 0; i--)
            {
                if (index + i < n)
                {
                    result = result || solver(index + i, nums);
                }
            }
        }

        return t[index] = result;
    }
    bool canJump(vector<int> &nums)
    {
        n = nums.size();
        memset(t, -1, sizeof(t));
        return solver(0, nums);
    }
};
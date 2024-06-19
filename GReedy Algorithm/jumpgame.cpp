#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int n;

    bool canJump(vector<int> &nums)
    {
        int max_index=0;
        n = nums.size();
        for (int i = 0; i < nums.size(); i++)
        {
            if(i > max_index)return false;
            max_index=max(nums[i]+i,max_index);
            
        }
        return true;
    }
};
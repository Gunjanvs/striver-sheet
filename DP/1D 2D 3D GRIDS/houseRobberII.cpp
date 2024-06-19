#include <iostream>
#include<algorithm>
using namespace std;
int rob(vector<int> &nums)
{
    int prev_i = nums[0];
    int prev2 = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        int take = nums[i];
        if (i > 1)
        {
            take += prev2;
        }
        int non = 0 + prev_i;
        int curr_i = max(take, non);
        prev2 = prev_i;
        prev_i = curr_i;
    }
    return prev_i;
}
int main()
{
    vector<int> nums{2, 3, 2};

    vector<int> temp1, temp2;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i != 0)
        {
            temp1.push_back(nums[i]);
        }

        if (i != nums.size() - 1)
        {
            temp2.push_back(nums[i]);
        }
    }

    int ans1 = rob(temp1);
    int ans2 = rob(temp2);
    cout << max(ans1, ans2);
}
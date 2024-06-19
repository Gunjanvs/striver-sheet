#include <iostream>
#include <vector>
using namespace std;

void nextPermutation(vector<int> &nums)
{
    int n = nums.size();
    int index = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            index = i;
            break;
        }
    }
    // we got the index now find the smallest one greater that that index but should not be less
    if (index != -1)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] > nums[index])
            {
                swap(nums[i], nums[index]);
                break;
            }
        }
        // reverese the array
        reverse(nums.begin() + index + 1, nums.end());
    }
    else
    {
        reverse(nums.begin(), nums.end());
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    // f(nums.size(), nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}
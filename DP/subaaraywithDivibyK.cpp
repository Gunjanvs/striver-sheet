#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int n = nums.size();
        int ans = 0;
        // for(int i=0;i<n;i++){
        //     int sum =0;
        //     for(int j=i;j <n;j++){
        //         sum += nums[j];
        //         if(sum %k==0)ans++;
        //     }
        // }
        // return ans ;
        // stack<int> st;
        // int sum = 0;
        // for(int i=0;i <n ;i++){
        //     sum += nums[i];
        //     if(sum %k==0){
        //         ans++;
        //         // check the top of unorderedset
        //         if(st.top()/sum == sum/st.top())ans++;
        //         st.push(sum);
        //     }
        // }
        // return ans ;
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            int rem = sum % k;
            if(rem <0)rem+=k;
            if (mp.find(rem) != mp.end())
            {
                ans += mp[rem] + 1;
            }
            mp[rem]++;
        }
        return ans ;
    }
};
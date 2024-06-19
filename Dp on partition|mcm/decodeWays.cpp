#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isValid(string s, int start, int end)
    {
        string t = s.substr(start, end - start + 1);
        if (t.size() == 0 || (t.size() > 1 && t[0] == '0'))
            return false;
        int num = stoi(t);
        return num >= 1 && num <= 26;
    }
    int f(int index, string &s,vector<int>&dp)
    {
        if (index == s.size())
        {
            return 1;
        }
        if(dp[index]!=-1)return dp[index];
        int ans = 0;
        for (int i = index; i < s.size(); i++)
        {
            if (isValid(s, index, i))
            {
                ans += f(i + 1, s,dp);
            }
        }
        return dp[index]= ans;
    }
    int numDecodings(string s)
    {
        int n =s.size();
        vector<int> dp(n+1,-1);
        return f(0,s,dp);
    }
};
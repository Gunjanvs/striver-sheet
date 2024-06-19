#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Function to check if string s can be formed by adding exactly one character to string t
    bool compare(string &s, string &t)
    {
        if (s.size() != t.size() + 1)
            return false;
        int first = 0;
        int second = 0;
        while (first < s.size())
        {
            if (s[first] == t[second])
            {
                first++;
                second++;
            }
            else
            {
                first++;
            }
        }
        return first == s.size() && second == t.size();
    }

    // Main function to find the longest string chain
    int longestStrChain(vector<string> &words)
    {
        int n = words.size();
        int maxi = 0;
        vector<int> dp(n + 1, 1); // DP array to store the length of the longest chain ending at each word

        // Sort words by length using a lambda function
        sort(words.begin(), words.end(), [](string &s1, string &s2)
             { return s1.size() < s2.size(); });

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (compare(words[i], words[j]) && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                }
            }
            if (dp[i] > maxi)
            {
                maxi = dp[i];
            }
        }
        return maxi;
    }
};

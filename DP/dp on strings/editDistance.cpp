#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int f(int i, int j, string s, string t)
    {
        if (i < 0)
            return j + 1;
        if (j < 0)
            return i + 1;
        if (s[i] == t[j])
        {
            return f(i - 1, j - 1, s, t);
        }
        int in = 1 + f(i, j - 1, s, t);
        int repl = 1 + f(i - 1, j - 1, s, t);
        int del = 1 + f(i - 1, j, s, t);
        return min(in, min(repl, del));
    }
    int minDistance(string word1, string word2)
    {
        int n = word1.length();
        int m = word2.length();
        return f(n - 1, m - 1, word1, word2);
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        for (int j = 0; j <= m; j++)
        {
            dp[0][j] = j;
        }
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = i;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (word1[i-1] == word2[j-1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    int in = 1 + dp[i][j - 1];
                    int repl = 1 + dp[i - 1][j-1];
                    int del = 1 + dp[i - 1] [j];
                    dp[i][j] = min(in, min(repl, del));
                }
            }
        }
        return dp[n][m];
    }
};
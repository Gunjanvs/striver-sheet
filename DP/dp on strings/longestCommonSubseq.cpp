#include <iostream>
#include <vecintrin.h>
#include <vector>
using namespace std;
class Solution
{
public:
    int f(int index1, int index2, string text1, string text2)
    {
        if (index1 < 0 || index2 < 0)
            return 0;

        if (text1[index1] == text2[index2])
        {
            return 1 + f(index1 - 1, index2 - 1, text1, text2);
        }
        return max(f(index1 - 1, index2, text1, text2), f(index1, index2 - 1, text1, text2));
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        // see the base case
        for (int i = 0; i <= m; i++)
        {
            dp[0][i] = 0;
        }
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        int length = dp[n][m];
        string s = "";
        for (int i = 0; i < length; i++)
        {
            s += '$';
        }
        int i = n, j = m;
        int index = length - 1;
        while (i > 0 && j > 0)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                s[index] = text1[i - 1];
                index--;
                i--;
                j--;
            }
            else
            {
                if (dp[i - 1][j] > dp[i][j - 1])
                    i = i - 1;
                else
                    j = j - 1;
            }
        }
        cout << s << endl;
        return dp[n][m];
    }
};

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        if (i < 0) {
            int ans = 0;
            while (j >= 0) {
                ans += (int)s2[j];
                j--;
            }
            return ans;
        }
        if (j < 0) {
            int ans = 0;
            while (i >= 0) {
                ans += (int)s1[i];
                i--;
            }
            return ans;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (s1[i] == s2[j]) {
            return dp[i][j] = f(i - 1, j - 1, s1, s2, dp);
        } else {
            int deleteFromS1 = (int)s1[i] + f(i - 1, j, s1, s2, dp);
            int deleteFromS2 = (int)s2[j] + f(i, j - 1, s1, s2, dp);
            return dp[i][j] = min(deleteFromS1, deleteFromS2);
        }
    }

    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, s1, s2, dp);
    }
};

// int main() {
//     Solution sol;
//     string s1 = "sea";
//     string s2 = "eat";
//     cout << sol.minimumDeleteSum(s1, s2) << endl; // Output: 231
//     return 0;
// }

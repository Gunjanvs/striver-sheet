#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
// class Solution {
// public:
//     string clearDigits(string s) {
//         while (true) {
//             int ind = -1;

//             for (int i = 0; i < s.size(); ++i) {
//                 if (isdigit(s[i])) {
//                     ind = i;
//                     break;
//                 }
//             }
//             // If no digit is found, break the loop
//             if (ind == -1) break;
            
//             int leftIndex = -1;
//             for (int i = ind - 1; i >= 0; --i) {
//                 if (isalpha(s[i])) {
//                     leftIndex = i;
//                     break;
//                 }
//             }
//             s.erase(ind, 1);
//             if (leftIndex != -1) {
//                 s.erase(leftIndex, 1);
//             }
//         }
//         return s;
//     }
// };
#include <vector>
#include <queue>

class Solution {
public:
    int findWinningPlayer(std::vector<int>& skills, int k) {
        int n = skills.size();
        std::deque<int> q;
        for (int i = 0; i < n; ++i) {
            q.push_back(i);
        }

        int hereWinner = q.front();
        int continuewin = 0;

        while (continuewin < k) {
            int player1 = q.front(); q.pop_front();
            int player2 = q.front(); q.pop_front();

            if (skills[player1] > skills[player2]) {
                hereWinner = player1;
                q.push_back(player2);
                q.push_front(player2);
                continuewin++;
            } else {
                hereWinner = player2;
                q.push_back(player1);
                q.push_front(player2);
                continuewin = 1; // player2 has won one game now
            }
        }

        return hereWinner;
    }
};

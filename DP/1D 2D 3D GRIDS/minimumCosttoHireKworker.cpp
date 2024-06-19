#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

class Solution {
    double f(vector<int>& quality, vector<int>& min_wage, int k){
        double ans = 0;
        for(int manager = 0; manager < quality.size();manager++){
            int manager_ratio= min_wage[manager]/quality[manager];
            vector<int> ans;
            for(int worker = 0; worker < min_wage.size();worker++){
                int worker_wage = manager_ratio * quality[worker];
                if(worker_wage >= min_wage[worker])ans.push_back(worker_wage);
            }
            if(ans.size() <2)continue;
            priority_queue <int, vector<int>, greater<int>> pq;
            for (int i = 0; i < ans.size(); i++)
            {
                pq.push(ans[i]);
            }
            while(k >0 && !pq.empty()){
                ans += pq.top();
                pq.pop();
                k--;
            }
        }
        return ans ;
    }
};
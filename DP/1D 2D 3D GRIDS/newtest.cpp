#include <iostream>
#include <vector>
#include <cmath>
#include<unordered_map>
using namespace std;

int solver(vector<int> arr, int n, int x, int y) {
    // find pairs
    int ans = 0;
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = i + 1; j < arr.size(); j++) { // Start j from i + 1
            if ((arr[i] + arr[j]) % x == 0 && (abs(arr[j] - arr[i]) % y == 0)) {
                ans++;
            }
        }
    }
    return ans;
}

int ans(vector<int> &arr,int n){
    unordered_map<int,int> mpp;
    // int elem =0;
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        // if (mpp.find(arr[i])!=mpp.end())
        // {
        //     elem++;
        // }
        mpp[arr[i]]++;
        if(mpp[arr[i]]> maxi){
            maxi= mpp[arr[i]];
        }
    }

    return arr.size()-maxi;

}
// int main() {
//     int t;
//     cin >> t;
//     while (t > 0) {
//         // int n, x, y;
//         int n;
//         // cin >> n>>x>>y;
//         vector<int> arr(n);
//         for (int i = 0; i < n; i++) {
//             cin >> arr[i];
//         }
//         // // cin >> x >> y;
//         // cout << solver(arr, n, x, y) << endl;
//         cout << ans(arr,n)<<endl;
//         t--;
//     }
//     return 0;
// }

int minBurles(vector<int>& arr) {
    unordered_map<int, int> freq;
    int maxFreq = 0;
    
    // Calculate frequency of each element
    for (int num : arr) {
        freq[num]++;
        maxFreq = max(maxFreq, freq[num]);
    }
    
    // Minimum burles required
    return arr.size() - maxFreq;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        
        cout << minBurles(arr) << endl;
    }
    
    return 0;
}
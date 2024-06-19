//{ Driver Code Starts
#include <iostream>
#include <vector>
using namespace std;

class Array
{
public:
    template <class T>
    static void input(vector<T> &A, int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

// } Driver Code Ends

class Solution
{
public:
    int LongestBitonicSequence(int n, vector<int> &arr)
    {
        // code here
        vector<int> dp1(n, 1); // dp1[i] stores the length of the longest increasing subsequence ending at arr[i]
        vector<int> dp2(n, 1); // dp2[i] stores the length of the longest decreasing subsequence ending at arr[i]

        // Calculate the longest increasing subsequence
        for (int i = 0; i < n; i++)
        {
            for (int prev_index = 0; prev_index < i; prev_index++)
            {
                if (arr[prev_index] < arr[i])
                {
                    dp1[i] = max(dp1[i], 1 + dp1[prev_index]);
                }
            }
        }

        // Reverse the direction of nested loops to calculate the longest decreasing subsequence
        for (int i = n - 1; i >= 0; i--)
        {
            for (int prev_index = n - 1; prev_index > i; prev_index--)
            {
                if (arr[prev_index] < arr[i])
                {
                    dp2[i] = max(dp2[i], 1 + dp2[prev_index]);
                }
            }
        }

        int res = 0;

        // Find the maximum length of the bitonic subsequence
        for (int i = 0; i < n; i++)
        {
            if (dp1[i] > 1 && dp2[i] > 1)
                res = max(res, dp1[i] + dp2[i] - 1);
        }

        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int n;
        scanf("%d", &n);

        vector<int> nums(n);
        Array::input(nums, n);

        Solution obj;
        int res = obj.LongestBitonicSequence(n, nums);

        cout << res << endl;
    }
}

// } Driver Code Ends
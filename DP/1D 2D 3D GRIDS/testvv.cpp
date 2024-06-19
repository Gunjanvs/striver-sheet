#include<iostream>
#include<vector>
using namespace std ;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i =0,j=0;
        while(i < m && j < n){
            if(nums1[i]>nums2[j]){
                int temp1 = nums1[i];
                int temp2 = nums2[j];
                nums1[i] = temp2;
                nums2[j] = temp1;
            }
            if(nums1[i] == 0){
                // means we came to end 
                nums1[i] = nums2[j];
                j++;
            }
            i++;
        }
        // if some is left behind means 
    }

int main(){

}
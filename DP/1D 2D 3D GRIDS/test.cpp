#include<iostream>
#include<queue>
using namespace std;

vector<int> ans(vector<int> &arr,int k,int n){
    int x =0 ;
    int j =k-1;
    vector<int> ans;
    while (x <= j && j < n)
    {   
        bool flag = false;
        for (int i = x; i <=j; i++)
        {
            if (arr[i] < 0)
            {
                ans.push_back(arr[i]);
                flag = true;
                x++;
                j++;
                break;
            }
            
        }
        if (!flag)
        {
            ans.push_back(0);
            x++;
            j++;
        }
         
    }
    return ans;
}

void cd(int index,vector<char> ds,vector<char> &alpha,int target){
    if (ds.size() == 3)
    {
        if (target == 0)
		{
			for (int i = 0; i < ds.size(); ++i)
			{
				cout << ds[i]<<" ";
			}
			cout << endl;
			return ;
		}
		else return ;
    }

    if (index > target)
    {
        return ;
    }
    
    if (index <= target)
    {
        //take the elment 
        ds.push_back(alpha[index]);
        cd(index,ds,alpha,target-index);
        ds.pop_back();
    }

    // not take 
    cd(index+1,ds,alpha,target);

}
int main()
{
    int t;
    cin>>t;    
    vector<char> alpha({ 
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'});
    while(t-->0)
    {
        vector<char> ds;
          int k;
          cin>>k;
          string output;
          bool go = false;
          cd(0,ds,alpha,k);
               
    }
}
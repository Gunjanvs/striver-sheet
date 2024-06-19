#include <iostream>
using namespace std;

int countPairs(int n)
{
    // Write your code here.
    // int ans = 0;
    // for (int x = 1; x < 10001; x++)
    // {
    //     // find the value of y
    //     int y = 0;
    //     if (x != n)
    //     {
    //         y = (x * n) / (x - n);
    //     }
    //     if(y < 0)continue;
    //     int t = (x * y) / (x + y);
    //     cout <<"x :"<<x<<" "<<y<<" "<<t <<endl;
    //     if (t == n)
    //     {
    //         ans++;
    //     }
    // }
    // return ans;
    int ans = 0;
    for(int a = 1; a <=n; a++){
        // check if a id divisible 
        if(n%a == 0){
            int b = (n*n)/a;
            int x  = a+n;
            int y = b+n;
            if(x > 0  && y > 0){
                if(x != y)ans=ans+2;
                else ans++;
            }
        }
    }
    return ans ;
}
int main(){
    cout << countPairs(5);
}
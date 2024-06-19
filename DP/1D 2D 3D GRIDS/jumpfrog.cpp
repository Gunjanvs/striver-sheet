#include <iostream>
using namespace std;

bool canCross(int index, vector<int> &stones, vector<int> &dp,int k)
{
    if(index == stones.size()-1){
        return true;
    }
    
    bool alpha = canCross(index +k +1,stones,dp,k+1);
    bool gama = false;
    bool beta =false;
    if(k >0 ){
        gama= canCross(index +k,stones,dp,k);
        
    }
    if(k-1 >0){
        beta= canCross(index +k-1,stones,dp,k-1);
    }
    
    if (alpha || gama || beta)
    {
        return true;
    }
    return false;
    
}
int main()
{
}
#include <iostream>
#include <cmath>
using namespace std;

bool help(int i, int n)
{
    if (i > n)
    {
        return false;
    }
    int value = pow(2, i);
    if (value == n)
    {
        return true;
    }
    if (value > n)
    {
        return false;
    }

    if (value < n)
    {
        if (help(i + 1, n))
        {
            return true;
        }
        // else
        //     return false;
    }
    return false;
    // for (long long i = x; i <= x; i++)
    // {
    //     long long value = pow(2, i);

    //     if (value == n)
    //     {
    //         return true;
    //     }
    //     if (value > n)
    //     {
    //         return false;
    //     }
    //     else
    //     {
    //         v
    //     }
    // }
}

// bool isPowerOfTwo(int n) {
//     if (n == 0)
//     {
//         return false;
//     }
//     bool flag = pow()
// }

int main()
{
    cout << help(0, 3);
}
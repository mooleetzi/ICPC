/*
    sb题
*/

#include <iostream>
using namespace std;
int main()
{
    int x;
    while (cin >> x && x)
    {
        if (x & 1)
            cout << "ailyanlu\n";
        else
            cout << "8600\n";
    }
    return 0;
}
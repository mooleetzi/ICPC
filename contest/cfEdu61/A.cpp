/*
    仔细读题
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int c1,c2,c3,c4;
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c1 >> c2 >> c3 >> c4;
    if (c1==c4){
        if (c1)
            cout << 1;
        else{
            if (c3)
                cout << 0;
            else
            {
                cout << 1;
            }
        }
    }
    else
    {
        cout << 0;
    }

    return 0;
}

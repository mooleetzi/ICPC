#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        ll a = x + y;
        if (a>z){
            if (y<=z||a-z<=z)
                cout << "-1\n";
            else
            {
                cout << a - z << "\n";
            }   
        }
        else if (a<z)
            cout << "-1\n";
        else
            cout << a+1 << "\n";
    }
    return 0;
}
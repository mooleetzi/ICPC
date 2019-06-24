#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k,t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        while(n&&k){
            if (n&1)
                ++n, n >>= 1;
            else
                n >>= 1;
            if (n==1)
                break;
            --k;
        }
        cout << n << "\n";
    }
    return 0;
}

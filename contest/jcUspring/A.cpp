#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
ull getFac(int n){
    ull ans = 1;
    for (int i = 2; i <= n;i++)
        ans *= i;
    return ans;
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    ull ans = 0;
    for (int i = 0; i < n;i++){
        int x;
        cin >> x;
        ans += getFac(x);
    }
    cout << ans;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
char s[maxn];
int n, m;
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t,k;
    cin >> t;
    while(t--){
        cin >> k;
        cin >> s;
        cin>>n>>m;
        for (int i = 0; i < m;i++){
            int x, y;
            cin >> x >> y;
        }
        int cur = (m - n + 1)%k;
        if (s[cur]=='1')
            cout << 2 << "\n";
        else
            cout << 1 << "\n";
    }
    return 0;
}

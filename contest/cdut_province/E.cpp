#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 10;
char s[maxn];
int n, k;
int judge(int l,char*ss){
    int t = 0,i=0;
    while(i<n){
        if (ss[i]=='1'){
            for (int j = i; j <= i + l && j < n;j++)
                ss[j] = '0';
            i += l-1;
            ++t;
        }
        i++;
    }
    return t <= k;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        cin >> s;
        int l = 0, r = n, ans;
        while(l<r){
            int mid = l + r >> 1;
            char ss[n + 2];
            memcpy(ss, s, sizeof(ss));
            if (judge(mid,ss)){
                r = mid;
                ans = mid;
            }
            else
                l = mid+1;
        }
        cout << ans+1 << "\n";
    }
    return 0;
}
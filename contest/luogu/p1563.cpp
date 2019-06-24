#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 1e5 + 10;
int to[maxn];
char s[maxn][12];
int n, m;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for (int i = 0; i < n;i++){
        cin >> to[i] >> s[i];
    }
    int cur = 0;
    for (int i = 0; i < m; i++)
    {
        int now, len;
        cin >> now >> len;
        if (now==0){
            if (to[cur])
                cur = (cur + len) % n;
            else cur = (cur + n - len) % n;
        }
        else
        {
            if (to[cur])
                cur = (cur - len + n) % n;
            else cur = (cur + len) % n;
        }
    }
    cout << s[cur];
    return 0;
}
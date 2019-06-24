#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 10;
int o[maxn], e[maxn];
int main(int argc, char const *argv[])
{
    int od = 0, ed = 0;
    int n;
    cin >> n;
    int om = 1e9, em = 1e9;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x&1){
            o[++od]=x;
        }
        else
        {

            e[++ed]=x;
        }

    }
    if (od==(n>>1)||ed==(n>>1)){
        cout << 0;
    }
    else{
        if (od>ed){
            sort(o + 1, o + 1 + od);
            int ans = 0;
            for (int i = 1; i < od - ed;i++)
                ans += o[i];
            cout << ans;
        }
        else
        {
            sort(e + 1, e + 1 + ed);
            int ans = 0;
            for (int i = 1; i < ed - od; i++)
                ans += e[i];
            cout << ans;
        }
    }
    return 0;
}

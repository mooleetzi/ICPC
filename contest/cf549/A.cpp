#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int p[maxn],a[maxn];
int n;
int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    int z = 0, o = 0;
    for (int i = n; i >= 1;i--){
        if (a[i]){
            p[i] = o;
            o = 1;
        }
        else
        {
            p[i] = z;
            z = 1;
        }
    }
    for (int i = 1; i <= n;i++)
        if (!p[i]){
            cout << i;
            return 0;
        }
        return 0;
}

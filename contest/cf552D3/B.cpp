#include<bits/stdc++.h>
using namespace std;
const int maxn = 110;
int n;
int a[maxn];
int getSuc(int a,int b){
    return abs(a - b);
}
int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    int f = 1,f2=1;
    sort(a + 1, a + 1 + n);
    for (int i = 2; i <= n;i++)
        if (a[i]!=a[1]){
            f2 = 0;
            break;
        }
    if (f2){
        cout << "0";
        return 0;
    }
    for (int i = 0; i <= 100; i++)
    {
        int pre = getSuc(a[1], i);
        int flag = 1;
        for (int j = 2; j <= n; j++)
            if (getSuc(a[j], i) != pre && getSuc(a[j], i) != 0)
            {
                flag = 0;
                break;
            }

        if (flag)
        {
            cout << pre;
            f = 0;
            break;
        }
        }
    if (f)
        cout << -1;
    return 0;
}

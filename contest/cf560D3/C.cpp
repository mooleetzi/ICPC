#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 2e5 + 10;
char s[maxn];
int n;
int b[maxn];
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> (s + 1);
    char p = s[1];
    int pre = 1;
    for (int i = 2; i <= n;i++){
        if (s[i]==p)
            b[i] = 0;
        else
        {

            b[i] = b[pre]=1;
            if (i==n)
                break;
            else  {
                p = s[i + 1];
                pre = i + 1;
                if (i+1==n)
                    break;
                i++;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n;i++)
        if (!b[i])
            ++ans;
    if ((n-ans)&1){
        cout << n << "\n";
        cout << "\n";
        return 0;
    }
    cout << ans << "\n";
    for (int i = 1; i <= n;i++)
        if (b[i])
            cout << s[i];
    cout << "\n";
    return 0;
}

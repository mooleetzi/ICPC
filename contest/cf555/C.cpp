#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
inline int read()
{
    register int f = 1, ans = 0;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        ans = (ans << 1) + (ans << 3) + ch - 48;
        ch = getchar();
    }
    return ans * f;
}
int n, m;
int a[maxn];
int main()
{
    n = read();
    int pre = -maxn;
    int left = 0, right = n - 1;
    for (int i = 0; i < n;i++){
        a[i] = read();
    }
    string ans = "";
    int sum = 0;
    while ((pre < a[left] || pre < a[right])&&(left<=right))
    {
        if (left!=right){
            if (a[left]>pre&&a[right]>pre){
                if (a[left]<a[right]){
                    pre = a[left++];
                    ans += "L";
                }
                else
                {
                    pre = a[right--];
                    ans += "R";
                }
            }
            else if (a[left]>pre)
            {
                ans += "L";
                pre = a[left++];
            }
            else if (a[right>pre])
            {
                ans += "R";
                pre = a[right--];
            }
            else
            {
                break;
            }
                }
        else
        {
            if (a[right]>pre){
                pre = a[right--];
                ans += "R";
            }
            else
            {
                break;
            }
                }
        
        ++sum;
    }
    cout << sum<< "\n"
         << ans;
}
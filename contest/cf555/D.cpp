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
    for (int i = 0; i < n; i++)
    {
        a[i] = read();
    }
    string ans = "";
    int sum = 0;
    while ((pre < a[left] || pre < a[right]) && (left <= right))
    {
        if (left != right)
        {
            if (a[left] > pre && a[right] > pre)
            {
                if (a[left] < a[right])
                {
                    pre = a[left++];
                    ans += "L";
                }
                else if (a[right]<a[left])
                {
                    pre = a[right--];
                    ans += "R";
                }
                else if (a[left]==a[right])
                {
                    int t1 = 0,t2=0;
                    for (int i = right-1; i >=left;i--)
                        if (a[i]>a[i+1])
                            ++t1;
                        else
                        {
                            break;
                        }
                    for (int i = left + 1; i <=right;i++)
                        if (a[i]>a[i-1])
                            ++t2;
                        else
                        {
                            break;
                        }
                    if (t1>t2){
                        for (int i = 0; i <=t1;i++)
                            ans += "R", ++sum;
                        break;
                    }
                    else
                    {
                        for (int i = 0; i <=t2; i++)
                            ans += "L", ++sum;
                        break;
                    }
                    
                }
            }
            else if (a[left] > pre)
            {
                ans += "L";
                pre = a[left++];
            }
            else if (a[right > pre])
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
            if (a[right] > pre)
            {
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
    cout << sum << "\n"
         << ans;
}
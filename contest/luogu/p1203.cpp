#include<bits/stdc++.h>
using namespace std;
const int maxn = 710;
char s[maxn];
int n, m;
int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 0; i < n;i++)
        cin >> s[i], s[i + n] = s[i];
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int l1 = 1, l2 = 1;
        int left = i;
        int right = i+1;
        char s1 = s[left], s2 = s[right];
        for (int j = right+1; j <right+n; j++)
        {
            if (s2 == 'w')
            {
                s2 = s[j];
                ++l2;
                continue;
            }
            if (s[j]==s2||s[j]=='w'){
                ++l2;
            }
            else
            {
                break;
            }
        }
        for (int j = left-1; j >left -n;j--){
            int t = j;
            if (t<0)
                t += n;
            if (s1=='w'){
                s1 = s[t];
                ++l1;
                continue;
            }
            if (s[t] == s1 || s[t] == 'w')
            {
                ++l1;
            }
            else
                break;
        }
        // cout << l1 << " " << l2 << " "<<i<<" "<<s1<<" "<<s2<<"\n";
        ans = max(ans, l1+l2);
        if (ans>n)
            ans = n;
    }
    cout << ans;
    return 0;
}

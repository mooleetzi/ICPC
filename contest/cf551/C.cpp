#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
char s[maxn];
int main(int argc, char const *argv[])
{
    int n;
    cin >> n>>s;
    int l = 0, r = 0;
    if (n&1||s[0]==')'||s[n-1]=='('){
        cout << ":(";
        return 0;
    }
    for (int i = 0; i < n;i++){
        if (s[i]=='(')
            ++l;
        if (s[i]==')')
            ++r;
    }
    int tot = 0;
    int mid = n / 2;
    for (int i = 0; i < n-1; i++)
    {
        if (s[i]=='('){
            ++tot;
        }
        else if (s[i]=='?'){
            if (l==mid){
                ++r;
                s[i] = ')';
                --tot;
                if (!tot){
                    cout << ":(";
                    return 0;
                }
            }
            else if (l<mid)
            {
                ++l;
                s[i] = '(';
                ++tot;
            }
        
        }
        else{
            --tot;
            if (!tot){
                cout << ":(";
                return 0;
            }
        }
    }
    if (tot==1){
        s[n - 1] = ')';
        cout << s;
    }
    else
    {
        cout << ":(";
    }

    return 0;
}

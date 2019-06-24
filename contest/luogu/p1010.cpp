#include <bits/stdc++.h>
using namespace std;
int f[16];
inline int getId(int n){
    int i;
    for (i = 1; i <= 15; i++)
        if (f[i]>n)
            break;
    return i-1;
}
void print(int n)
{
    if (n==1){
        cout << "2(0)";
    }
    else if (n==2){
        cout << "2";
    }
    else
    {
        if (getId(n)==1)
            cout << 2;
        else
        {
            cout << "2(";
            print(getId(n));
            cout << ")";
        }
        
        if (f[getId(n)]<n){
            cout << "+";
            print(n-f[getId(n)]);
        }
    }
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    f[0] = 1;
    for (int i = 1; i <= 15; i++)
        f[i] = f[i - 1] * 2;
    // cout << getId(n);
    print(n);
    return 0;
}

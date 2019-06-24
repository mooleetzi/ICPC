#include<iostream>
using namespace std;
const  int maxn=110;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n;
    cin >> x;
    if (x!=0&&(x>1||x<-1))
        cout << x << "x^" << n;
    else if (x==1)
        cout << "x^" << n;
    else if (x==-1)
        cout << "-x^" << n;
    for (int i = 1; i < n; i++)
    {
        int x;
        cin>>x;
        if (x>0)
            cout << "+";
        if (!x)
            continue;
        if (x>1||x<-1)
            cout << x << "x";
        else if (x==1)
            cout << "x";
        else if (x == -1)
            cout << "-x";
        if (n-i>1)
            cout << "^"<<n - i;
    }
    cin >> x;
    if (x>0)
        cout << "+" << x;
    else if (x<0)
    {
        cout << x;
    }
    return 0;
}
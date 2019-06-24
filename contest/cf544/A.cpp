#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int h1, h2, m1, m2, h, m;
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    char ch;
    cin >> h1 >> ch >> m1;
    cin >> h2 >> ch >> m2;
    if (h1>h2){
        swap(h1, h2);
        swap(m1, m2);
    }
    if (h1==h2&&m1>m2){
        swap(m1, m2);
    }
    int all = (h2 - h1-1) * 60 + (m2 + 60 - m1);
    all >>= 1;
    h = h1 + all / 60;
    m =m1+ all % 60;
    if (m>=60)
        ++h, m -= 60;
    cout << setw(2) << setfill('0') << h << ":" << setw(2) << setfill('0') << m;
    return 0;
}

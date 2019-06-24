#include<bits/stdc++.h>
using namespace std;
const int maxn = 110;
vector<char> e, d;
char c[maxn], l[maxn];
int n,m;
int getNum(char c){
    return c - 'a';
}
void print(vector<char> n){
    for (auto x:n)
        cout << x;
    cout << "\n";
}
int main(int argc, char const *argv[])
{
    cin >> n >> m;
    cin >> l >> c;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < 26;j++)
            if ((getNum(l[i])+j)%26==getNum(c[m-n+i]))
                e.emplace_back(j + 'a');
    }
    // reverse(e.begin(), e.end());
    auto it = e.begin();
    while (m-- >= n)
    {
        char t = c[m - n - 1];
        char b = *it;
        it--;
        int cur = getNum(t) - getNum(b);
        if (cur<0)
            cur += 26;
        e.emplace_back(cur + 'a');
    }
    reverse(e.begin(), e.end());
    print(e);
    return 0;
}

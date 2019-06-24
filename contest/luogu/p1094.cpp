#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e4 + 10;
deque<int> que;
inline void read(int &x){
    x = 0;
    register int f = 1;
    char ch = getchar();
    while(!isdigit(ch)){
        if (ch=='-')
            f = -1;
        ch = getchar();
    }
    while(isdigit(ch)){
        x = (x << 3) + (x << 1) + ch - 48;
        ch = getchar();
    }
    x *= f;
}
int main(){
    int n, w;
    read(w), read(n);
    for (int i = 0; i < n;i++){
        int x;
        read(x);
        que.push_back(x);
    }
    sort(que.begin(), que.end());
    int ans = 0;
    while (n>1)
    {
        if (que.front()+que.back()<=w){
            n -= 2;
            ++ans;
            que.pop_back();
            que.pop_front();
        }
        else
        {
            --n;
            ++ans;
            que.pop_back();
        }
    }
    if (n)
        ++ans;
    printf("%d", ans);
}
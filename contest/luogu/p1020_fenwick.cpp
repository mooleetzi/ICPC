#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
inline int lowbit(int x){
    return x&(-x);
}
int c[maxn];
void add(int x){
    while(x<maxn){
        x+=lowbit(x);
        ++c[x];
    }
}
int query(int x){
    int ans=0;

}
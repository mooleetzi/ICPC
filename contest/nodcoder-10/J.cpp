#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<set>
#include<algorithm>
#include<stack>
#include<map>
#include<cmath>
#include<string>
#include<vector>
#define rep(i,x,y) for (int i=x;i<y;i++)
#define max(x,y) x>y?x:y
#define min(x,y) x<y?x:y
#define maxn 1000100
#define m0(a) memset(a,0,sizeof a)
using namespace std;
int a[maxn];
typedef long long ll;
int read() {
    int x = 0;
    char c = getchar();
    while (c < '0' | c > '9')c = getchar();
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}
void write(int x) {
    int y = 10, len = 1;
    while (y <= x) {
        y *= 10;
        len++;
    }
    while (len--) {
        y /= 10;
        putchar(x / y + 48);
        x %= y;
    }
}
string s1,s2;
int main(){
    int T;
//    T=read();
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--){
        int n;
//        n=read();
//        gets(s1);
        cin>>n;
        cin>>s1;
        rep(i,1,n){
//            gets(s2);
            cin>>s2;
            int pos=-1;
            int len=s2.length();
            rep(j,0,len)
                if (s2[j]==s1[s1.length()-1]){
                    pos=j;
                    break;
                }
            if (pos!=-1&&pos!=len)
                s2.erase(0,pos+1);
            s1+=s2;
        }
        cout<<s1<<"\n";
    }
    return 0;
}


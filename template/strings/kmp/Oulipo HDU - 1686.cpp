//rm 关掉输入同步才过。
#include<iostream>
#include<cstring>
using namespace std;
string s,t;
int nextt[2000000];
void getnext();
int kmp();
int main(){
    int n;
    ios::sync_with_stdio(false);
    cin>>n;
    while(n--){
        cin>>t>>s;
        cout<<kmp()<<"\n";
    }
    return 0;
}
void getnext(){
    memset(nextt,0,sizeof(nextt));
    nextt[0]=-1;
    int i,j,l;
    j=-1;
    i=0;
    l=t.length();
    while(i<l){
        if (j==-1||t[i]==t[j])
            if (t[++i]!=t[++j])
                nextt[i]=j;
            else
                nextt[i]=nextt[j];
        else
            j=nextt[j];
    }
}
int kmp(){
    getnext();
    int al=s.length(),bl=t.length();
    int i=0,j=0,ans=0;
    while(i<al&&j<=bl){
        if (j==-1||s[i]==t[j])
            i++,j++;
        else
            j=nextt[j];
        if (j==bl)
            ans++;
    }
    return ans;
}

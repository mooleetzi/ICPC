#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

char s[1010],t[1010];
int nex[1010];
int ans;

void get_next(int tlen)
{
    int i=0, j=-1;
    nex[0]=-1;
    while(i<tlen)
    {
        if(j==-1||t[i]==t[j])
            nex[++i]=++j;
        else
            j=nex[j];
    }
}

void kmp(int slen,int tlen)
{
    int i=0,j=0;
    get_next(tlen);
    while(i<slen)
    {
        if(j==-1||s[i]==t[j])
        {
            i++;
            j++;
        }
        else
            j=nex[j];
        if(j==tlen)
        {
            ans++;
            j=0;
        }
    }
    cout<<ans<<"\n";
}

int main()
{
//ios::sync_with_stdio(false);
   // cin.tie(0);
    while(~scanf("%s",s)&&strcmp(s,"#"))
    {
        scanf("%s",t);
        ans=0;
        int slen=strlen(s);
        int tlen=strlen(t);
        kmp(slen,tlen);
    }
    return 0;
}

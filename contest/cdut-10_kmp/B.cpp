#include<cstdio>
#include<cstring>
const int maxn=1e4+10;
const int maxm=1e6+10;
char p[maxn],s[maxm];
int nxt[maxn];
void getNext(char p[],int m,int next[]){
    next[0]=-1;
    int i=0,j=-1;
    while(i<m){
        while(j!=-1&&p[i]!=p[j]) j=next[j];
        next[++i]=++j;
    }
}
int kmp(char p[],int m,char s[],int n){
    int i=0,j=0,ans=0;
    getNext(p,m,nxt);
    while(j<n){
        while(i!=-1&&p[i]!=s[j]) i=nxt[i];
        i++;j++;
        if (i>=m){
            ans++;
            i=nxt[i];
        }
    }
    return ans;
}
int main(){
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",p);
        scanf("%s",s);
        printf("%d\n",kmp(p,strlen(p),s,strlen(s)));
//        cout<<kmp(p,strlen(p),s,strlen(s))<<"\n";
    }
    return 0;
}

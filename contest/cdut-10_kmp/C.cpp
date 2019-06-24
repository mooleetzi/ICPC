#include<cstdio>
#include<cstring>
const int maxn=1e3+10;
char p[maxn],s[maxn];
int nxt[maxn];
void getNext(char p[],int m,int next[]){
    int i=0,j=-1;
    next[0]=-1;
    while(i<m){
        while(j!=-1&&p[i]!=p[j]) j=next[j];
        next[++i]=++j;
    }
}
int kmp(char p[],int m,char s[],int n){
    int i=0,j=0;
    int ans=0;
    getNext(p,m,nxt);
    while(i<n){
        while(j!=-1&&p[j]!=s[i]) j=nxt[j];
        i++,j++;
        if (j>=m){
            ans++;
            i+=nxt[j];
            j=nxt[j];
        }
    }
    return ans;
}
int main(){
    char ch;
    int m=0,n=0,flag=1;
    while(scanf("%s",s)&&s[0]!='#'){
        scanf("%s",p);
        printf("%d\n",kmp(p,strlen(p),s,strlen(s)));
    }
    return 0;
}

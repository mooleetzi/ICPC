#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
char s[100][52];
int getNum(char now[]){
    int ans=0;
    for (int i=0;i<n;i++)
        if (strcmp(now,s[i])==0)
            continue;
        else{
            int cur=0;
            char q[strlen(now)];
            memcpy(q,s[i],strlen(s[i]));
            while(strcmp(now,q)!=0){
                char c=q[0];
                for (int i=0;i<strlen(q)-1;i++)
                    q[i]=q[i+1];
                q[strlen(q)-1]=c;
                ++cur;
                if (cur>strlen(q))
                    break;
            }
            if (cur>strlen(q))
                return -1;
            ans+=cur;
        }
    return ans;
}
int main(){
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>s[i];
    int ans=0x3f3f3f3f;
    for (int i=0;i<n;i++ )
        ans=min(getNum(s[i]),ans);
    cout<<ans;
    return 0;
}

#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
using namespace std;
int a[101];
int b[101];
int tot;
char s[101];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
    char ch;
    for (int i=0;i<strlen(s);i++){
        if (s[i]>='a'&&s[i]<='z'){
            a[++tot]=i;
            ch=s[i];
        }
    }
    cout<<ch<<"=";
    int ind;
    for (int i=0;i<strlen(s);i++){
        if (s[i]=='='){
            ind=i;
            break;
        }
    }
    int left=0,right=0;
    for (int i=1;i<=tot;i++){
        if (a[i]<ind){
            int f=0,index,j,tmp=0;
            for (j=a[i]-1;j>-1;j--){
                if (s[j]=='+'){
                    f=1;
                    index=j;
                    break;
                }
                else if (s[j]=='-'){
                    f=-1;
                    index=j;
                    break;
                }
            }
            if (j==-1){
                index=-1;
                f=1;
            }
            for (int j=index+1;j<a[i];j++)
                tmp=tmp*10+s[j]-'0';
            tmp*=f;
            left+=tmp;
            if (tmp==0)
                left+=f;
        }
        else if (a[i]>ind){
            int f=0,index,j,tmp=0;
            for (j=a[i]-1;j>ind;j--){
                if (s[j]=='-'){
                    f=-1;
                    index=j;
                    break;
                }
                else if (s[j]=='+'){
                    f=1;
                    index=j;
                    break;
                }
            }
            if (j==ind){
                index=ind;
                f=1;
            }
            for (int j=index+1;j<a[i];j++)
                tmp=tmp*10+s[j]-'0';
            tmp*=f;
            right+=tmp;
            if (tmp==0)
                right+=f;
        }
    }
    int c=left-right;
    left=right=0;
    int now=0;
    for (int i=0;i<ind;){
        int tmp=0;
        int f=1;
        if (s[i]=='-'){
            i++;
            f=-1;
        }
        else if (s[i]=='+'){
            i++;
            f=1;
        }
        while(s[i]>='0'&&s[i]<='9'){
            tmp=tmp*10+s[i]-'0';
            i++;
        }
        if (s[i]==ch)
            i++;
        else
            left+=f*tmp;
    }
    for (int i=ind+1;i<strlen(s);){
        int tmp=0;
        int f=1;
        if (s[i]=='-'){
            i++;
            f=-1;
        }
        else if (s[i]=='+'){
            i++;
            f=1;
        }
        while(s[i]>='0'&&s[i]<='9'){
            tmp=tmp*10+s[i]-'0';
            i++;
        }
        if (s[i]==ch)
            i++;
        else
            right+=f*tmp;
    }
    double ans=(right-left)/(c*1.0);
    if (fabs(ans-0)<0.000001)
        cout<<"0.000";
    else
        cout<<fixed<<setprecision(3)<<ans;
    return 0;
}

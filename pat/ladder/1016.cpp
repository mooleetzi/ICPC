#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int num[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char c[]={'1','0','X','9','8','7','6','5','4','3','2'};
int b[101];
string s[101];
inline int isNum(char c){
    return (c>='0'&&c<='9');
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,ans=0;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>s[i];
        int sum=0;
        int flag=1;
        for (int j=0;j<17;j++){
            if (isNum(s[i][j]))
                sum+=(s[i][j]-'0')*num[j];
            else{
                flag=0;
                break;
            }
        }
        if (!flag){
            b[i]=1;
            ++ans;
            continue;
        }
        sum%=11;
        if (c[sum]!=s[i][s[i].size()-1]){
            b[i]=1;
            ++ans;
        }
    }
    if (!ans){
        cout<<"All passed";
    }
    else{
        cout<<ans<<"\n";
        for (int i=0;i<n;i++)
            if (b[i])
                cout<<s[i]<<"\n";
    }
    return 0;
}

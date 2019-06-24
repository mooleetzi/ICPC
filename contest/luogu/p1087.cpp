#include<bits/stdc++.h>
using namespace std;
const int maxn=(1<<10)+10;
char s[maxn];
int n;
int search(int l,int r){
    if (l==r){
        if (s[l]=='0'){
            cout<<'B';
            return 0;
        }
        cout<<'I';
        return 1;
    }
    int mid=l+r>>1; 
    int h=search(l,mid);
    int t=search(mid+1,r);
    if (h!=t){
        cout<<'F';
        return 2;
    }
    if (h==t){
        if (h==1){
            cout<<'I';
            return 1;
        }
        else if(h==0){
            cout<<'B';
            return 0;
        }
        else
        {
            cout<<'F';
            return 2;
        }
    }
}
int main(){
    cin>>n;
    cin>>s+1;
    int ans=search(1,1<<n);
    return 0;
}
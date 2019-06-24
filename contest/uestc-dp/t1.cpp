#include<iostream>
using namespace std;
int ans=0;
int n;
int main(){
    cin>>n;
    while(n--){
        int a,b,c;
        cin>>a>>b>>c;
        if(a+b+c>=2)
            ans++;
    }
    cout<<ans;
    return 0;
}

#include<iostream>
#include<cmath>
using namespace std;
inline int isOk(int x){
    return sqrt(x)*sqrt(x)!=x;
}
int main(){
    int n;
    cin>>n;
    int ans=-9999;
    for (int i=0;i<n;i++){
        int x;
        cin>>x;
        if (isOk(x)&&x>ans)
            ans=x;
    }
    cout<<ans<<'\n';
    return 0;
}

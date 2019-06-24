#include<iostream>
#define inf 0x3f3f3f3f
using namespace std;
long long sum=0;
int main(){
    int n;
    cin>>n;
    int mini=inf;
    int maxi=-inf;
    while(n--){
        int x;
        cin>>x;
        if (x>maxi)
            maxi=x;
        if (x<mini)
            mini=x;
        sum+=x;
    }
    cout<<mini<<" "<<maxi<<" "<<sum<<endl;
    return 0;
}

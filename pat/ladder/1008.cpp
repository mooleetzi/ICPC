#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int s,t,sum=0;
    cin>>s>>t;
    for (int i=s,j=1;i<=t;i++,j++){
        cout<<setw(5)<<i;
        if (j%5==0)
            cout<<"\n";
        sum+=i;
    }
    if ((t-s+1)%5!=0)
        cout<<"\n";
    cout<<"Sum = "<<sum;
    return 0;
}

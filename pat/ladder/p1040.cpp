#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    double now;
    char gender;
    int n;
    cin>>n;
    while(n--){
        cin>>gender>>now;
        if (gender=='M')
            cout<<fixed<<setprecision(2)<<now/1.09<<"\n";
        else
            cout<<fixed<<setprecision(2)<<now*1.09<<"\n";
    }
    return 0;
}

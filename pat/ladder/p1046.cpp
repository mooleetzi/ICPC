#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int tot=1;
    int now=1;
    while(tot<n){
        ++now;
        tot=10*tot+1;
    }
    while(1){
        if (tot%n==0){
            cout<<tot/n;
            break;
        }
        else{
            cout<<tot/n;
            tot%=n;
            tot*=10;
            ++tot;
        }
        ++now;
    }
    cout<<" "<<now;
    return 0;
}

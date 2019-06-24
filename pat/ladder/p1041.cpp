#include<iostream>
using namespace std;
int main(){
    for (int i=1;;i++){
        int x;
        cin>>x;
        if (x==250){
            cout<<i<<"\n";
            return 0;
        }
    }
    return 0;
}

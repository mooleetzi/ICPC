#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        string now;
        int h1,h2;
        cin>>now>>h1>>h2;
        if (h1>20||h1<15||h2<50||h2>70)
            cout<<now<<"\n";
    }
    return 0;
}

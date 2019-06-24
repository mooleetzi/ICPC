#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        string n;
        int h1,h2;
        cin>>n>>h1>>h2;
        if (h1<15||h1>20||h2<50||h2>70)
            cout<<n<<"\n";
    }
    return 0;
}

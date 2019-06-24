#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    char c;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>c;
    for (int i=0;i<(n+1)/2;i++){
        for (int j=0;j<n;j++)
            cout<<c;
        cout<<"\n";
    }
    return 0;
}

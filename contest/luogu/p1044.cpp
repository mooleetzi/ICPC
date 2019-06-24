#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
long long search(int n){
    if (n==1)
        return 1;
    if (n==2)
        return 2;
    return 2*(2*n-1)*search(n-1)/(n+1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    cout<<search(n);
    return 0;
}

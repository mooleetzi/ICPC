#include<iostream>
#include<cmath>
using namespace std;
int is_prime(int n){
    if (n==2)
        return 1;
    for (int i=2;i<=sqrt(n)+1;i++)
        if (n%i==0)
            return 0;
    return 1;
}
int main(){
    int n;
    cin>>n;
    for (int i=0;i<n-1;i++){
        int x;
        cin>>x;
        if (is_prime(x))
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    cin>>n;
    if (is_prime(n))
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}

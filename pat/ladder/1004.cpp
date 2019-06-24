#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    double n;
    cin>>n;
    cout<<"Celsius = ";
    cout<<(int)(5*(n-32)/9);
    return 0;
}

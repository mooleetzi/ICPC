#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int a[10];
int main(){
    ios::sync_with_stdio(false);
    string n;
    cin>>n;
    for (int i=0;i<n.length();i++)
        a[n[i]-48]++;
    for (int i=0;i<10;i++)
    if (a[i]){
        cout<<i<<":"<<a[i]<<"\n";
    }
}

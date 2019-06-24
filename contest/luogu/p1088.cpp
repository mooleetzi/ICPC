#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n,m;
    cin>>n;
    cin>>m;
    int a[n+1];
    for (int i=0;i<n;i++)
        cin>>a[i];
    while(m--){
        next_permutation(a,a+n);
    }
    for (int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
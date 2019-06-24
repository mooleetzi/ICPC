#include<iostream>
#include<cmath>
using namespace std;
const int maxn=1e4+10;
int a[maxn];
int minx=999999;
string s[maxn];
int main(){
    int n;
    cin>>n;
    int sum=0;
    for (int i=0;i<n;i++){
        cin>>s[i]>>a[i];
        sum+=a[i];
    }
    int ave=sum/n/2;
    int ind;
    for (int i=0;i<n;i++){
        if (abs(a[i]-ave)<minx){
            ind=i;
            minx=abs(a[i]-ave);
        }
    }
    cout<<ave<<" "<<s[ind];
}

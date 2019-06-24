#include<bits/stdc++.h>
using namespace std;
const int maxn=5100;
int a[maxn],b[maxn];
void print(int a[]){
    int ti=0;
    if (a[0]<500)
        for (int i=0;i<500-a[0];i++){
            cout<<0;
            ++ti;
            if (ti==50){
                ti=0;
                cout<<"\n";
            }
        }
    for (int i=a[0];i>=1;i--){
        cout<<a[i];
        ++ti;
        if (ti==50){
            cout<<"\n";
            ti=0;
        }
    }
    cout<<"\n";
}
void multiply(int a[],int b[]){
    int c[maxn*maxn/100]={0};
    c[0]=a[0]+b[0];
    if (c[0]>500)
        c[0]=500;
    for (int i=1;i<=a[0];i++)
        for (int j=1;j<=b[0];j++){
            c[i+j-1]+=a[i]*b[j];
            if (c[i+j-1]>9){
                c[i+j]+=c[i+j-1]/10;
                c[i+j-1]%=10;
            }
        }
    for (int i=0;i<=c[0];i++)
        a[i]=c[i];
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    b[0]=1;
    b[1]=2;
    a[0]=1;
    a[1]=1;
    cout<<floor(n*log10(2)+1)<<"\n";
    while(n){
        if (n&1)
            multiply(a,b);
        multiply(b,b);
        n>>=1;
    }
    a[1]--;
    print(a);
    return 0;
}

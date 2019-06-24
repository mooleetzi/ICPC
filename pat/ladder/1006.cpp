#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
int isPrime(int num){
    for (int i=2;i<sqrt(num)+1;i++)
        if (num%i==0)
            return 0;
    return 1;
}
int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    if (isPrime(n)){
        cout<<"1\n"<<n;
        return 0;
    }
    int s,len=0,fac;
    for (int i=2;i<sqrt(n)+1;i++){
        if (n%i==0){
            fac=i;
            int j;
            for (j=i+1;j<sqrt(n)+1;j++){
                fac*=j;
                if (n%fac!=0)
                    break;
            }
            if (j-i>len){
                len=j-i;
                s=i;
            }
        }
    }
    cout<<len<<"\n";
    for (int i=s;i<s+len-1;i++)
        cout<<i<<"*";
    cout<<s+len-1;
    return 0;
}

#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<string>
using namespace std;
int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int t=a*b*c;
    a=t/a;
    b=t/b;
    c=t/c;
    string s="123456789";
    int flag=0;
    do{
        int a1=stoi(s.substr(0,3));
        int a2=stoi(s.substr(3,3));
        int a3=stoi(s.substr(6,3));
        if (a1*a==a2*b&&a3*c==a1*a){
            cout<<a1<<" "<<a2<<" "<<a3<<"\n";
            flag=1;
        }
    }while(next_permutation(s.begin(),s.end()));
    if (!flag)
        cout<<"No!!!";
    return 0;
}

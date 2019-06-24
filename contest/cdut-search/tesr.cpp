#include<iostream>
using namespace std;
int main(){
    string c="aaabbb";
    string a,b;
    for (int i=0;i<3;i++)
        a+=c[i];
    for (int i=3;i<6;i++)
        b+=c[i];
    cout<<a<<"\n"<<b;
    return 0;
}

#include<iostream>
using namespace std;
int main(){
    string s="I Love GPLT";
    for (int i=0;i<s.size()-1;i++)
        cout<<s[i]<<"\n";
    cout<<s.back();
    return 0;
}

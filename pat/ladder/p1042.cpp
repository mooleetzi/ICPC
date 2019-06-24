#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    int m,d,y;
    char ch;
    cin>>m>>ch>>d>>ch>>y;
    cout<<y<<ch<<setw(2)<<setfill('0')<<right<<m<<ch<<setw(2)<<setfill('0')<<d;
    return 0;
}

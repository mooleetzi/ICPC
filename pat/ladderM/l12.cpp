#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    int h,m;
    char ch;
    cin>>h>>ch>>m;
    if (h<12)
        cout<<"Only "<<setw(2)<<setfill('0')<<right<<h<<":"<<setw(2)<<setfill('0')<<right<<m<<".  Too early to Dang.";
    else{
        int all=h-12;
        if (m)
            all++;
        for (int i=0;i<all;i++)
            cout<<"Dang";
    }
    return 0;
}

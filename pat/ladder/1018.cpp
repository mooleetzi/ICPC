#include<iostream>
#include<algorithm>
using namespace std;
inline int getNum(const string &a,int s){
    return (a[s]-48)*10+a[s+1]-48;
}
string s="Dang";
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string now;
    cin>>now;
    int h=getNum(now,0);
    int m=getNum(now,3);
    if (h<12||(h==12&&m==0)){
        cout<<"Only "<<now<<".  Too early to Dang.";
    }
    else{
        for (int i=12;i<h;i++)
            cout<<s;
        if (m)
        cout<<s;
    }
    return 0;
}

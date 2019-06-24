#include<iostream>
using namespace std;
int getNum(string ss,int s,int t){
    int ans=0;
    for (int i=s;i<t;i++){
        int now=ss[i]-48;
        if (now>9||now<0)
            return -1;
        ans=ans*10+now;
    }
    if (ans<1||ans>1000)
        return -1;
    return ans;
}
int main(){
    string s;
    getline(cin,s);
    int ind;
    for (int i=0;i<s.size();i++)
    if (s[i]==' '){
        ind=i;
        break;
    }
    int a=getNum(s,0,ind);
    int b=getNum(s,ind+1,s.size());
    if (a==-1||b==-1){
        if (a==-1)
            cout<<"?";
        else
            cout<<a;
        cout<<" + ";
        if (b==-1)
            cout<<"?";
        else
            cout<<b;
        cout<<" = ?";
    }
    else
        cout<<a<<" + "<<b<<" = "<<a+b;
    return 0;
}

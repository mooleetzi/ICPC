#include<iostream>
#include<iomanip>
using namespace std;
string s[]={"JianDao","ChuiZi","Bu"};
int a[3];
int main(){
    int n;
    cin>>n;
    a[0]=1;
    a[1]=2;
    a[2]=0;
    int tot=1;
    while(1){
        string now;
        cin>>now;
        if (now=="End")
            break;
        int ind;
        for (int j=0;j<3;j++)
        if (s[j]==now)
            ind=j;
        if (tot%(n+1)==0)
            cout<<now<<"\n";
        else
            cout<<s[a[ind]]<<"\n";
        ++tot;
    }
    return 0;
}

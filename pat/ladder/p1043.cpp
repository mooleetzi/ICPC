#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;
const int maxn=1010;
struct tim{
    int h,m;
    tim(){}
    tim(int hh,int mm){
        h=hh;
        m=mm;
    }
    int operator-(const tim&a)const{
        if (h==a.h)
            return m-a.m;
        else{
            int allMin=(h-a.h)*60;
            allMin+=m-a.m;
            return allMin;
        }
    }
};
struct node{
    tim in,out;
    node(){}
    void setIn(tim a){
        in=a;
    }
    void setOut(tim a){
        out=a;
    }
    int getTime(){
        return in-out;
    }
}a[maxn];
int b[maxn];
int main(){
    int n;
    cin>>n;
    while(n--){
        int tot=0;
        int ans=0;
        int ind;
        char s,ch;
        int h,m;
        memset(b,0,sizeof b);
        while(cin>>ind>>s>>h>>ch>>m&&ind)
        if (s=='S'){
            if (b[ind]==0){
                b[ind]=1;
                a[ind].setOut(tim(h,m));
            }
            else
                continue;
        }
        else if (s=='E'){
            if (b[ind]){
                b[ind]=0;
                tot++;
                a[ind].setIn(tim(h,m));
                ans+=a[ind].getTime();
            }
            else
                continue;
        }
        if (tot){
            int q=ans/(tot*1.0)+0.5;
            cout<<tot<<" "<<q<<"\n";
        }
        else
            cout<<"0 0\n";
    }
    return 0;
}

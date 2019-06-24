#include<iostream>
using namespace std;
double s,x,cur=7,dis=0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s>>x;
    while(dis<s-x){
        dis+=cur;
        cur*=0.98;
    }
    int left=dis-s+x;
    int right=2*x-left;
    if (cur>right)
        cout<<"n"<<"\n";
    else
        cout<<"y"<<"\n";
    return 0;
}

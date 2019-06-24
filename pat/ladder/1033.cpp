#include<iostream>
#include<unordered_set>
#include<iomanip>
using namespace std;
int isOk(int now,int n){
    unordered_set<int> s;
    if (now<1000)
        s.insert(0);
    while(now){
        s.insert(now%10);
        now/=10;
    }
    if (s.size()==n)
        return 1;
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int s,n;
    cin>>s>>n;
    int now=s;
    while(!isOk(now++,n));
    cout<<now-s-1<<" "<<setw(4)<<setfill('0')<<right<<now-1;
    return 0;
}

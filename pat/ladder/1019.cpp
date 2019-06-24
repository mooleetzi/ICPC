#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a,b,n;
    cin>>a>>b;
    cin>>n;
    int s=0,t=0;
    int flag=1;
    for (int i=0;i<n;i++){
        int x,y,q,w;
        cin>>x>>y>>q>>w;
        if (y==x+q&&w!=x+q)
            ++s;
        else if (w==x+q&&y!=x+q)
            ++t;
        if (s>a){
            cout<<"A\n"<<t;
            break;
        }
        if (t>b){
            cout<<"B\n"<<s;
            break;
        }
    }

    return 0;
}

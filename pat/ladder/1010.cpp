#include<iostream>
//#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int x,y,z;
    cin>>x>>y>>z;
    if (x>y)
        swap(x,y);
    if (y>z)
        swap(y,z);
    if (x>y)
        swap(x,y);
    cout<<x<<"->"<<y<<"->"<<z;
    return 0;
}

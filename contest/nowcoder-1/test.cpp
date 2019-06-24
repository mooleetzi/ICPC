#include<bits/stdc++.h>
using namespace std;
int lowbit(int x){
    return (x&-x);
}
int main(){
    cout<<lowbit(100);
    return 0;
}

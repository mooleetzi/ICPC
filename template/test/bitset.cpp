#include<bits/stdc++.h>
using namespace std;
inline int lowbit(int x){
    return (x&-x);
}
int main(){
    for (int i=1;i<10;i++){
        cout<<lowbit(i)<<" ";
    }
    return 0;
}

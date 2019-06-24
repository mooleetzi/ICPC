#include<iostream>
using namespace std;
inline int get(char a){
    return a-'A'+1;
}
int main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        char op,ch,ans;
        for (int j=0;j<4;j++){
            cin>>op>>ch>>ans;
            if (ans=='T')
                cout<<get(op);
        }
    }
    return 0;
}

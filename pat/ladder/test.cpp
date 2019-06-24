#include<iostream>
using namespace std;
int main(){
    int a[][3]={1,4,7,2,5,8,3,6,9};
    int i,k=2;
    for (int i=0;i<3;i++)
        cout<<a[k][i]<<" ";
    return 0;
}
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int odd=0,even=0;
    for (int i=0;i<n;i++){
        int x;
        cin>>x;
        if (x&1)
            ++odd;
        else
            ++even;
    }
    cout<<odd<<" "<<even;
    return 0;
}

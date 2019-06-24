#include<iostream>
std::string s[]={"1","2","4","8","16","32","64","128","256","512","1024"};
int main(){
    int n;
    std::ios::sync_with_stdio(false);
    std::cin>>n;
    std::cout<<"2^"<<n<<"=";
    std::cout<<s[n];
    return 0;
}

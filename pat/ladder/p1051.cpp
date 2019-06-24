#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    double price,discount;
    cin>>price>>discount;
    cout<<fixed<<setprecision(2)<<price*discount/10;
    return 0;
}

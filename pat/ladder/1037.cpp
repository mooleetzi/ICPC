#include<iostream>
#include<iomanip>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  if (m<0)
    cout<<n<<"/("<<m<<")=";
  else if (m>=0)
    cout<<n<<"/"<<m<<"=";
  if (m==0)
    cout<<"Error";
  else
    cout<<fixed<<setprecision(2)<<n/(m*1.0);
  return 0;
}

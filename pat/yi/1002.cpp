#include<iostream>
#include<vector>
using namespace std;
string s[]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
int main(){
    ios::sync_with_stdio(false);
    string str;
    cin>>str;
    int num=0;
    for (int i=0;i<str.length();i++)
        num+=str[i]-48;
    vector<string> ans;
    ans.clear();
    while(num){
        ans.push_back(s[num%10]);
        num/=10;
    }
    for (vector<string>::iterator it=ans.end()-1;it!=ans.begin();it--)
        cout<<*it<<" ";
    cout<<ans[0];
    return 0;
}

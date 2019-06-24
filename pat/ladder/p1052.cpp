#include<iostream>
#include<cstring>
using namespace std;
int isOk(string s){
    for (int i=0;i<s.size()/2;i++)
        if (s[i]!=s[s.size()-i-1])
            return 0;
    return 1;
}
string s[110];
int main(){
    char ch;
    int l;
    cin>>ch>>l;
    cin.get();
    for (int i=0;i<l;i++)
        getline(cin,s[i]);
    int flag=1;
    for (int i=0;i<l;i++){
        string ss="";
        for (int j=0;j<l;j++)
            ss+=s[j][i];
        if (!isOk(ss)){
            flag=0;
            break;
        }
    }
    if (flag){
        cout<<"bu yong dao le\n";
        for (int i=0;i<l;i++){
            for (int j=0;j<l;j++)
                if (s[i][j]!=' ')
                    cout<<ch;
                else
                    cout<<" ";
            cout<<"\n";
        }
    }
    else{
        for (int i=0;i<l;i++){
            for (int j=0;j<l;j++)
                if (s[l-i-1][l-j-1]!=' ')
                    cout<<ch;
                else
                    cout<<' ';
            cout<<"\n";
        }
    }
    return 0;
}

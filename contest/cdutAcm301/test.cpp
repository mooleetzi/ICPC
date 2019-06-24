#include<iostream>
using namespace std;
int main(){
    string s[6];
    s[0]="F";
    for (int i=1;i<6;i++){
        s[i]=s[i-1];
        s[i]+="L";
        for (int j=s[i-1].length()-1;j>-1;j--)
            if (s[i-1][j]=='L')
                s[i]+="R";
            else if (s[i-1][j]=='R')
                s[i]+="L";
            else s[i]+="F";
    }
    for (int i=0;i<6;i++)
        cout<<s[i]<<"\n";
    return 0;
}

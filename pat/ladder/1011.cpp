#include<iostream>
#include<cstring>
using namespace std;
const int maxNum=1e4+10;
char s1[maxNum],s2[maxNum];
int b[300];
int main(){
    ios::sync_with_stdio(false);
    cin.getline(s1,maxNum);
    cin.getline(s2,maxNum);
    int l1=strlen(s1);
    int l2=strlen(s2);
    for (int i=0;i<l2;i++)
        b[s2[i]]=1;
    for (int i=0;i<l1;i++)
        if (!b[s1[i]])
            cout<<s1[i];
    return 0;
}

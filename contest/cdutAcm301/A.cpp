#include<iostream>
#include<cstring>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    char s[11];
    int ans=0;
    cin.getline(s,11);
    for (int i=0;i<strlen(s);i++){
        if (s[i]==' ')
            continue;
        ans++;
    }
    cout<<ans;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int s[4];
int a, b, c;
int main(int argc, char const *argv[])
{
    for (int i = 0; i < 4;i++)
        cin >> s[i];
    sort(s, s + 4);
    for (int i = 1; i <s[0];i++){
        int a = i;
        int b = s[0] - a;
        int c = s[1] - a;
        if (b+c==s[2]&&a+b+c==s[3]){
            cout << a << " " << b << " " << c;
            break;
        }
    }
    return 0;
}

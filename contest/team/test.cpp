#include<bits/stdc++.h>
using namespace std;
char s[110] = "pirpumsemoystoal";
char a[110] = "marywasnosyagain";
int getNum(char c){
    return c - 'a';
}
int main(int argc, char const *argv[])
{

    for (int i = 0; i < 16;i++){
        for (int j = 0; j < 26;j++)
            if ((j+getNum(a[i]))%26==getNum(s[i]))
                cout << (char)(j + 'a');
    }
    return 0;
}

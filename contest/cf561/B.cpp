#include<iostream>
using namespace std;
const int maxn = 1e4 + 10;
int n;
char s[6] = "aeiou";
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int f = 0;
    for (int i = 5; i * i <= n&&!f;i++){
        if (n%i==0&&n/i>=5){
            f = 1;
            for (int j = 0; j < i;j++){
                for (int k = j; k < j + n / i;k++){
                    cout << s[k % 5];
                }
            }
        }
    }
    if (!f)
        cout << -1;
        return 0;
}

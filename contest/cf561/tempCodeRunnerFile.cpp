#include<iostream>
using namespace std;
const int maxn = 1e4 + 10;
int n;
char s[5][6] = {"aeiou","eioua","iouae","ouaei","uaeio"};
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
                if (j>=5){
                    for (int k = 0; k < n / i;k++)
                        cout << char('a' + k % 26);
                }
                else{
                    cout << s[j];
                    for (int k = 0; k < n / i - 5;k++)
                        cout << char('a' + k % 26);
                }
            }
        }
    }
    if (!f)
        cout << -1;
        return 0;
}

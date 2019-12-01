#include<iostream>
using namespace std;
typedef long long ll;
ll n;
int main(int argc, char const *argv[])
{
    ll f[35];
    f[0] = 0, f[1] = 1;
    for (int i = 2; i <31;i++)
        f[i] = f[i - 1] + f[i - 2];
    cin >> n;
    cout << f[n] << endl;
    return 0;
}
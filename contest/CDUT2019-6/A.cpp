#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;
using ld = long double;
const ld pi = acos(-1.0);
const ld eps = 0.0000005;
int A, B;
inline ld getC(ld a, ld b)
{
    return a * b * pi + 2 * b * b;
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)

    {
        cin >> A >> B;
        ld a = A;
        ld b = B;
        ld ans = getC(a, b) / b;
        cout << fixed << setprecision(6) << ans - eps << "\n";
    }
    return 0;
}

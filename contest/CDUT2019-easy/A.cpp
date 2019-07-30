#include <cmath>
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int tot = 1;
    double m;
    while (cin >> m)
    {
        int ans = m / log2(10);
        cout << "Case #" << tot++ << ": " << ans << "\n";
    }
    return 0;
}

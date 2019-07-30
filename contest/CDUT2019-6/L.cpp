//第一次垂直下落到斜面 v=sqrt(2gh)
//分解为垂直斜面方向vy=v*cosx vx=v*sinx
//同理分解重力加速度 gy=g*cosx gx=g*sinx
//垂直斜面方向计算每次空中时间 t=2*vy/gy
//平行斜面匀加速 由每次时间计算出停止的次数
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
using ld = long double;
const ld pi = acos(-1.0);
const ld g = 9.8;
ld a, b, x, y;
int ans;
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ans = 1;
        ld v1, v2, v3, gx, gy, t1, t2;
        cin >> a >> b >> x >> y;
        ld r = atan(b / a);
        ld w = g * (y - (-x) * (b / a));
        gx = g * cos(r);
        gy = g * sin(r);
        v1 = sqrt(2 * w) * cos(r);
        v2 = sqrt(2 * w) * sin(r);
        t1 = 2 * (v1 / gx);
        v3 = sqrt((-2 * x) * gy / cos(r) + v2 * v2);
        t2 = (v3 - v2) / gy;
        ans += (int)(t2 / t1);
        cout << ans << "\n";
    }
    return 0;
}

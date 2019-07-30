//相切直接加
//相交剪一段弧，加一段弧

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 110;
const double eps = 0.000001;
const double pi = acos(-1.0);
int v[maxn][maxn];
struct circle
{
    double x, y, r;
    circle() {}
    circle(double xx, double yy, double rr) : x(xx), y(yy), r(rr) {}
} c[maxn];
int m, R;
inline double dis(circle &a, circle &b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
inline int inqie(circle &a, circle &b)
{
    double r = fabs(a.r - b.r);
    double d = dis(a, b);
    if (fabs(r - d) < eps)
        return 1;
    return 0;
}
inline int intersect(circle &a, circle &b)
{
    double r1 = fabs(a.r - b.r);
    double r2 = a.r + b.r;
    double d = dis(a, b);
    return d > r1 && d < r2;
}
inline int outqie(circle &a, circle &b)
{
    double r = fabs(a.r + b.r);
    double d = dis(a, b);
    if (fabs(r - d) < eps)
        return 1;
    return 0;
}
int main(int argc, char const *argv[])
{
    int t;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> m >> R;
        vector<circle> qie;
        memset(v, 0, sizeof v);
        double ans = 2 * pi * R;
        for (int i = 0; i < m; i++)
        {
            double x, y, r;
            cin >> x >> y >> r;
            c[i] = circle(x, y, r);
        }
        circle out(0, 0, R);
        for (int i = 0; i < m; i++)
        {
            if (inqie(out, c[i]))
            {
                ans += 2 * c[i].r * pi;
                qie.emplace_back(c[i]);
                continue;
            }
            if (intersect(out, c[i]))
            {
                double A = out.r;
                double B = c[i].r;
                double C = dis(out, c[i]);
                double y = acos((A * A + C * C - B * B) / (2 * A * C));
                double x = y * 2;
                ans -= A * x;
                double D = sqrt(A * A + (C - B) * (C - B) - 2 * A * (C - B) * cos(y));
                y = acos((2 * B * B - D * D) / (2 * B * B));
                x = y * 2;
                ans += B * x;
                qie.emplace_back(c[i]);
            }
        }
        cout << fixed << setprecision(6) << ans << "\n";
    }
    return 0;
}

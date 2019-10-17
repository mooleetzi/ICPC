#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

const int INF = 0x3f3f3f3f;

int t;
double ans[30];

struct Point
{
    double x, y, z;
} a, b, c, d, e, f;

double calc(Point p1, Point p2, Point p3, Point p4)
{
    double a1 = (p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y) + (p2.z - p1.z) * (p2.z - p1.z),
           b1 = 0.0 - ((p2.x - p1.x) * (p4.x - p3.x) + (p2.y - p1.y) * (p4.y - p3.y) + (p2.z - p1.z) * (p4.z - p3.z)),
           c1 = (p1.x - p2.x) * (p1.x - p3.x) + (p1.y - p2.y) * (p1.y - p3.y) + (p1.z - p2.z) * (p1.z - p3.z),
           a2 = 0.0 - ((p2.x - p1.x) * (p4.x - p3.x) + (p2.y - p1.y) * (p4.y - p3.y) + (p2.z - p1.z) * (p4.z - p3.z)),
           b2 = (p4.x - p3.x) * (p4.x - p3.x) + (p4.y - p3.y) * (p4.y - p3.y) + (p4.z - p3.z) * (p4.z - p3.z),
           c2 = (p1.x - p3.x) * (p4.x - p3.x) + (p1.y - p3.y) * (p4.y - p3.y) + (p1.z - p3.z) * (p4.z - p3.z);
    double t = (a1 * c2 - a2 * c1) / (a1 * b2 - a2 * b1),
           s = (c1 - b1 * t) / a1;
    // debug    printf("%.8lf %.8lf\n", s, t);
    if (s >= 0.0 && s <= 1.0 && t >= 0.0 && t <= 1.0)
    {
        double x = p1.x + s * (p2.x - p1.x),
               y = p1.y + s * (p2.y - p1.y),
               z = p1.z + s * (p2.z - p1.z),
               u = p3.x + t * (p4.x - p3.x),
               v = p3.y + t * (p4.y - p3.y),
               w = p3.z + t * (p4.z - p3.z);
        return sqrt((x - u) * (x - u) + (y - v) * (y - v) + (z - w) * (z - w));
    }
    else
    {
        double t1 = ((p3.x - p1.x) * (p3.x - p4.x) + (p3.y - p1.y) * (p3.y - p4.y) + (p3.z - p1.z) * (p3.z - p4.z)) / ((p3.x - p4.x) * (p3.x - p4.x) + (p3.y - p4.y) * (p3.y - p4.y) + (p3.z - p4.z) * (p3.z - p4.z)),
               t2 = ((p3.x - p2.x) * (p3.x - p4.x) + (p3.y - p2.y) * (p3.y - p4.y) + (p3.z - p2.z) * (p3.z - p4.z)) / ((p3.x - p4.x) * (p3.x - p4.x) + (p3.y - p4.y) * (p3.y - p4.y) + (p3.z - p4.z) * (p3.z - p4.z)),
               t3 = ((p1.x - p3.x) * (p1.x - p2.x) + (p1.y - p3.y) * (p1.y - p2.y) + (p1.z - p3.z) * (p1.z - p2.z)) / ((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y) + (p1.z - p2.z) * (p1.z - p2.z)),
               t4 = ((p1.x - p4.x) * (p1.x - p2.x) + (p1.y - p4.y) * (p1.y - p2.y) + (p1.z - p4.z) * (p1.z - p2.z)) / ((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y) + (p1.z - p2.z) * (p1.z - p2.z));
        double d1, d2, d3, d4;
        if (t1 < 0.0)
            d1 = sqrt((p3.x - p1.x) * (p3.x - p1.x) + (p3.y - p1.y) * (p3.y - p1.y) + (p3.z - p1.z) * (p3.z - p1.z));
        else if (t1 > 1.0)
            d1 = sqrt((p4.x - p1.x) * (p4.x - p1.x) + (p4.y - p1.y) * (p4.y - p1.y) + (p4.z - p1.z) * (p4.z - p1.z));
        else
        {
            double x = p3.x + t * (p4.x - p3.x);
            double y = p3.y + t * (p4.y - p3.y);
            double z = p3.z + t * (p4.z - p3.z);
            d1 = sqrt((x - p1.x) * (x - p1.x) + (y - p1.y) * (y - p1.y) + (z - p1.z) * (z - p1.z));
        }
        if (t2 < 0.0)
            d2 = sqrt((p3.x - p2.x) * (p3.x - p2.x) + (p3.y - p2.y) * (p3.y - p2.y) + (p3.z - p2.z) * (p3.z - p2.z));
        else if (t2 > 1.0)
            d2 = sqrt((p4.x - p2.x) * (p4.x - p2.x) + (p4.y - p2.y) * (p4.y - p2.y) + (p4.z - p2.z) * (p4.z - p2.z));
        else
        {
            double x = p3.x + t * (p4.x - p3.x);
            double y = p3.y + t * (p4.y - p3.y);
            double z = p3.z + t * (p4.z - p3.z);
            d2 = sqrt((x - p2.x) * (x - p2.x) + (y - p2.y) * (y - p2.y) + (z - p2.z) * (z - p2.z));
        }
        if (t3 < 0.0)
            d3 = sqrt((p1.x - p3.x) * (p1.x - p3.x) + (p1.y - p3.y) * (p1.y - p3.y) + (p1.z - p3.z) * (p1.z - p3.z));
        else if (t3 > 1.0)
            d3 = sqrt((p2.x - p3.x) * (p2.x - p3.x) + (p2.y - p3.y) * (p2.y - p3.y) + (p2.z - p3.z) * (p2.z - p3.z));
        else
        {
            double x = p1.x + t * (p2.x - p1.x);
            double y = p1.y + t * (p2.y - p1.y);
            double z = p1.z + t * (p2.z - p1.z);
            d3 = sqrt((x - p3.x) * (x - p3.x) + (y - p3.y) * (y - p3.y) + (z - p3.z) * (z - p3.z));
        }
        if (t4 < 0.0)
            d4 = sqrt((p1.x - p4.x) * (p1.x - p4.x) + (p1.y - p4.y) * (p1.y - p4.y) + (p1.z - p4.z) * (p1.z - p4.z));
        else if (t4 > 1.0)
            d4 = sqrt((p2.x - p4.x) * (p2.x - p4.x) + (p2.y - p4.y) * (p2.y - p4.y) + (p2.z - p4.z) * (p2.z - p4.z));
        else
        {
            double x = p1.x + t * (p2.x - p1.x);
            double y = p1.y + t * (p2.y - p1.y);
            double z = p1.z + t * (p2.z - p1.z);
            d4 = sqrt((x - p4.x) * (x - p4.x) + (y - p4.y) * (y - p4.y) + (z - p4.z) * (z - p4.z));
        }
        return min(d1, min(d2, min(d3, d4)));
    }
}

double calc_(Point p0, Point p1, Point p2, Point p3)
{
    double l = (p2.y - p1.y) * (p3.z - p1.z) - (p3.y - p1.y) * (p2.z - p1.z),
           m = (p2.z - p1.z) * (p3.x - p1.x) - (p3.z - p1.z) * (p2.x - p1.x),
           n = (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);
    double t = (l * (p1.x - p0.x) + m * (p1.y - p0.y) + n * (p1.z - p0.z)) / (l * l + m * m + n * n);
    double X = p0.x + t * l,
           Y = p0.y + t * m,
           Z = p0.z + t * n;
    double l1 = fabs((p2.y - Y) * (p3.z - Z) - (p3.y - Y) * (p2.z - Z)),
           l2 = fabs((Y - p1.y) * (p3.z - p1.z) - (p3.y - p1.y) * (Z - p1.z)),
           l3 = fabs((p2.y - p1.y) * (Z - p1.z) - (Y - p1.y) * (p2.z - p1.z)),
           m1 = fabs((p2.z - Z) * (p3.x - X) - (p3.z - Z) * (p2.x - X)),
           m2 = fabs((Z - p1.z) * (p3.x - p1.x) - (p3.z - p1.z) * (X - p1.x)),
           m3 = fabs((p2.z - p1.z) * (X - p1.x) - (Z - p1.z) * (p2.x - p1.x)),
           n1 = fabs((p2.x - X) * (p3.y - Y) - (p3.x - X) * (p2.y - Y)),
           n2 = fabs((X - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (Y - p1.y)),
           n3 = fabs((p2.x - p1.x) * (Y - p1.y) - (X - p1.x) * (p2.y - p1.y));
    // debug    printf("%.8lf %.8lf %.8lf %.8lf %.8lf %.8lf %.8lf %.8lf %.8lf %.8lf %.8lf %.8lf\n", l1, l2, l3, l, m1, m2, m3, m, n1, n2, n3, n);
    if (l1 + l2 + l3 == fabs(l) || m1 + m2 + m3 == fabs(m) || n1 + n2 + n3 == fabs(n))
        return sqrt((X - p0.x) * (X - p0.x) + (Y - p0.y) * (Y - p0.y) + (Z - p0.z) * (Z - p0.z));
    else
    {
        double t1 = ((p1.x - p0.x) * (p1.x - p2.x) + (p1.y - p0.y) * (p1.y - p2.y) + (p1.z - p0.z) * (p1.z - p2.z)) / ((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y) + (p1.z - p2.z) * (p1.z - p2.z)),
               t2 = ((p2.x - p0.x) * (p2.x - p3.x) + (p2.y - p0.y) * (p2.y - p3.y) + (p2.z - p0.z) * (p2.z - p3.z)) / ((p2.x - p3.x) * (p2.x - p3.x) + (p2.y - p3.y) * (p2.y - p3.y) + (p2.z - p3.z) * (p2.z - p3.z)),
               t3 = ((p3.x - p0.x) * (p3.x - p1.x) + (p3.y - p0.y) * (p3.y - p1.y) + (p3.z - p0.z) * (p3.z - p1.z)) / ((p3.x - p1.x) * (p3.x - p1.x) + (p3.y - p1.y) * (p3.y - p1.y) + (p3.z - p1.z) * (p3.z - p1.z));
        double d1, d2, d3;
        if (t1 < 0.0)
            d1 = sqrt((p1.x - p0.x) * (p1.x - p0.x) + (p1.y - p0.y) * (p1.y - p0.y) + (p1.z - p0.z) * (p1.z - p0.z));
        else if (t1 > 1.0)
            d1 = sqrt((p2.x - p0.x) * (p2.x - p0.x) + (p2.y - p0.y) * (p2.y - p0.y) + (p2.z - p0.z) * (p2.z - p0.z));
        else
        {
            double x = p1.x + t * (p2.x - p1.x);
            double y = p1.y + t * (p2.y - p1.y);
            double z = p1.z + t * (p2.z - p1.z);
            d1 = sqrt((x - p0.x) * (x - p0.x) + (y - p0.y) * (y - p0.y) + (z - p0.z) * (z - p0.z));
        }
        if (t2 < 0.0)
            d2 = sqrt((p2.x - p0.x) * (p2.x - p0.x) + (p2.y - p0.y) * (p2.y - p0.y) + (p2.z - p0.z) * (p2.z - p0.z));
        else if (t2 > 1.0)
            d2 = sqrt((p3.x - p0.x) * (p3.x - p0.x) + (p3.y - p0.y) * (p3.y - p0.y) + (p3.z - p0.z) * (p3.z - p0.z));
        else
        {
            double x = p2.x + t * (p3.x - p2.x);
            double y = p2.y + t * (p3.y - p2.y);
            double z = p2.z + t * (p3.z - p2.z);
            d2 = sqrt((x - p0.x) * (x - p0.x) + (y - p0.y) * (y - p0.y) + (z - p0.z) * (z - p0.z));
        }
        if (t3 < 0.0)
            d3 = sqrt((p3.x - p0.x) * (p3.x - p0.x) + (p3.y - p0.y) * (p3.y - p0.y) + (p3.z - p0.z) * (p3.z - p0.z));
        else if (t3 > 1.0)
            d3 = sqrt((p1.x - p0.x) * (p1.x - p0.x) + (p1.y - p0.y) * (p1.y - p0.y) + (p1.z - p0.z) * (p1.z - p0.z));
        else
        {
            double x = p3.x + t * (p1.x - p3.x);
            double y = p3.y + t * (p1.y - p3.y);
            double z = p3.z + t * (p1.z - p3.z);
            d3 = sqrt((x - p0.x) * (x - p0.x) + (y - p0.y) * (y - p0.y) + (z - p0.z) * (z - p0.z));
        }
        return min(d1, min(d2, d3));
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf", &a.x, &a.y, &a.z, &b.x, &b.y, &b.z, &c.x, &c.y, &c.z, &d.x, &d.y, &d.z, &e.x, &e.y, &e.z, &f.x, &f.y, &f.z);
        memset(ans, 0, sizeof(ans));
        ans[1] = calc(a, b, d, e);
        ans[2] = calc(a, b, e, f);
        ans[3] = calc(a, b, f, d);
        ans[4] = calc(b, c, d, e);
        ans[5] = calc(b, c, e, f);
        ans[6] = calc(b, c, f, d);
        ans[7] = calc(c, a, d, e);
        ans[8] = calc(c, a, e, f);
        ans[9] = calc(c, a, f, d);
        ans[10] = calc(d, e, a, b);
        ans[11] = calc(d, e, b, c);
        ans[12] = calc(d, e, c, a);
        ans[13] = calc(e, f, a, b);
        ans[14] = calc(e, f, b, c);
        ans[15] = calc(e, f, c, a);
        ans[16] = calc(f, d, a, b);
        ans[17] = calc(f, d, b, c);
        ans[18] = calc(f, d, c, a);
        ans[19] = calc_(a, d, e, f);
        ans[20] = calc_(b, d, e, f);
        ans[21] = calc_(c, d, e, f);
        ans[22] = calc_(d, a, b, c);
        ans[23] = calc_(e, a, b, c);
        ans[24] = calc_(f, a, b, c);
        double Min = INF;
        for (int i = 1; i <= 24; i++)
            // debug            printf("%.8lf\n", ans[i]);
            Min = min(Min, ans[i]);
        printf("%.8lf\n", Min);
    }
}
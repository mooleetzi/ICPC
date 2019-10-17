#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
using namespace std;
#define ll long long
#define P pair<ll, ll>
int t;
ll n;
ll maxx, maxy, max_x;
ll cntx1, cntx2, cnty1, cnty2;
ll cnt1, cnt2;
/*
记录每个点的横纵坐标所在行列的点的数目
找到最大的maxx,maxy,max_x = maxx+maxy
其实消灭蟑螂的最大数目只能是max_x,或者max_x-1
cnt1 :  max_x 的集合数目
cnt2 :  max_x -1  集合数目
*/
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("biaoda.out", "w", stdout);
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        scanf("%lld", &n);
        map<ll, ll> cntx, cnty;
        vector<P> ve(n); //必须为 ()，
        maxx = 0;
        maxy = 0;
        for (auto &it : ve)
        { //前面ve(n)一定要是n，不然输入不完
            scanf("%d%d", &it.first, &it.second);
            maxx = max(maxx, ++cntx[it.first]);
            maxy = max(maxy, ++cnty[it.second]);
        }
        //两个if为特判
        if (cntx.size() == 1 || cnty.size() == 1)
        {
            printf("Case %d: %lld 1\n", i, n);
            continue;
            //cntx.size()==1时全在一列，只有maxx,不存在maxx-1
        }
        if (maxx == 1 && maxy == 1)
        { //一定是&&
            printf("Case %d: 2 %lld\n", i, n * (n - 1) / 2);
            continue;
        }
        cntx1 = 0, cntx2 = 0;
        cnty1 = 0, cnty2 = 0;
        for (auto &it : cntx)
        {
            if (it.second == maxx)
                cntx1++;
            else if (it.second == maxx - 1)
                cntx2++;
        }
        for (auto &it : cnty)
        {
            if (it.second == maxy)
                cnty1++;
            else if (it.second == maxy - 1)
                cnty2++;
        }
        max_x = maxx + maxy; //在最好情况下，下面的两个式子成立
        cnt1 = cntx1 * cnty1;
        cnt2 = cntx1 * cnty2 + cnty1 * cntx2;
        //只需要遍历输入的所有点，因为cntx[]==0||cnty[]==0的无意义
        for (auto &it : ve)
        {
            ll num = cntx[it.first] + cnty[it.second];
            if (num == max_x)
            {
                cnt1--; //这个点会让max_x变为max_x -1
                cnt2++;
            }
            else if (num == max_x - 1)
                cnt2--; //这个点会让max_x -1变为max_x -2
        }
        if (cnt1 > 0)
        {
            printf("Case %d: %lld %lld\n", i, max_x, cnt1);
        }
        else
            printf("Case %d: %lld %lld\n", i, max_x - 1, cnt2);
    }
    return 0;
}
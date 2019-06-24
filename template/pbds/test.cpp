#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

const int MAXN = 3000000 + 10;

int price, menu[MAXN], cnt[MAXN];

typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> rbtree;

int n, opt, x;

rbtree tre;

int main()
{
    scanf("%d", &price);
    int id = 1;
    while (~scanf("%d", &opt) && opt)
    {
        scanf("%d", &x);
        if (opt == 1)
        { /// add price of x
            tre.insert(x);
            cnt[x]++;       /// 价格x的菜的数量
            menu[id++] = x; /// 第id道菜价格x
            continue;
        }
        if (opt == 2)
        {
            int p = menu[x];
            if (cnt[p])
            {
                cnt[p]--;
            }
            continue;
        }
        if (opt == 3)
        {
            int res = *tre.find_by_order(x - 1);
            if (res > price)
            {
                puts("Dui bu qi,Mei you.");
            }
            else if (cnt[res] == 0)
            {
                puts("Mei you. Zhe ge ke yi you. Zhe ge zhen mei you!");
            }
            else
            {
                printf("You. %d Yuan.\n", res);
            }
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int main(int argc, char const *argv[])
{
    cin >> a >> b >> c;
    int ans = 0;

    for (int i = 1; i <= 7; i++)
    {
        int ta = a, tb = b, tc = c, j, now = 0;
        for (j = i; ta && tb && tc; j++)
        {
            if (j > 7)
                j -= 7;
            if (ta/3&&tb/2&&tc/2){
                int cur = ta / 3;
                cur = min(tb / 2, cur);
                cur = min(tc / 2, cur);
                ta -= cur * 3;
                tb -= cur * 2;
                tc -= cur * 2;
                now += cur * 7;
            }
            if (!ta||!tb||!tc){
                j++;
                break;
            }
            if (j == 1 || j == 4 || j == 7)
            {
                --ta;
                ++now;
            }
            else if (j == 2 || j == 6)
            {
                --tb;
                ++now;
            }
            else
            {
                --tc;
                ++now;
            }
        }
        if (j > 7)
            j -= 7;
        if (!ta&&!tb&&!tc){}
        else
        {
            if (!ta)
            {
                if (j != 1)
                    now += 2;
            }
            if (!tb)
            {
                if (j == 3)
                {
                    if (tc >= 2)
                        now += 3;
                    else
                    {
                        now += 2;
                    }
                }
                else
                {
                    if (ta >= 2)
                        now += 2;
                    else
                    {
                        now += 1;
                    }
                }
            }
            if (!tc)
            {
                if (j == 4)
                    now += 1;
                else
                {
                    if (tb >= 2 && ta >= 2)
                        now += 4;
                    else if (ta == 1)
                    {
                        now += 2;
                    }
                    else if (ta >= 2 && tb == 1)
                    {
                        now += 3;
                    }
                }
            }
        }
        ans = max(ans, now);
    }
    cout << ans;
    return 0;
}

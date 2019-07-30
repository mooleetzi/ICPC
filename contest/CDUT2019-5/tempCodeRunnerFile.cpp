#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 12;
int n, k;
bool cmp(int x, int y)
{
    return x > y;
}
int get_min(int *b)
{
    for (int i = 0; i < 10; i++)
        if (b[i])
            return i;
}
int get_max(int *b)
{
    for (int i = 9; i >= 0; i--)
        if (b[i])
            return i;
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
        int minx, maxx;
        vector<int> d;
        cin >> n >> k;
        int tmp = n;
        while (tmp)
        {
            d.emplace_back(tmp % 10);
            tmp /= 10;
        }
        reverse(d.begin(), d.end());
        int l = d.size();
        if (k >= (l - 1) * l / 2)
        {
            sort(d.begin(), d.end());
            int ind = 0;
            for (ind = 0; ind < l; ind++)
                if (d[ind])
                    break;
            swap(d[0], d[ind]);
            minx = 0;
            for (int i = 0; i < l; i++)
                minx = minx * 10 + d[i];
            sort(d.begin(), d.end(), cmp);
            maxx = 0;
            for (int i = 0; i < l; i++)
                maxx = maxx * 10 + d[i];
            cout << minx << " " << maxx << "\n";
        }
        else
        {
            int b[10];
            deque<int> w[10];
            memset(b, 0, sizeof b);
            for (int i = 0; i < l; i++)
            {
                ++b[d[i]];
                w[d[i]].emplace_back(i);
            }
            int now = 0;
            for (int i = 0; i < k; i++)
            {
                int cnt = get_min(b);
                if (!now && !cnt)
                {
                    for (int i = 1; i <= 9; i++)
                        if (b[i])
                        {
                            cnt = i;
                            break;
                        }
                    deque<int>::iterator end = w[cnt].end() - 1;
                    deque<int>::iterator begin = w[d[now]].begin();
                    int e = w[cnt].back();
                    swap(d[now], d[e]);
                    w[cnt].erase(end);
                    w[cnt].emplace_front(now);
                    w[d[e]].erase(begin);
                    w[d[e]].emplace_back(e);
                    --b[cnt];
                    ++now;
                }
                else
                {
                    if (now >= l)
                        break;
                    if (d[now] == cnt)
                    {
                        i -= 1;
                        now++;
                        --b[cnt];
                        continue;
                    }
                    deque<int>::iterator end = w[cnt].end() - 1;
                    deque<int>::iterator begin = w[d[now]].begin();
                    int e = w[cnt].back();
                    swap(d[now], d[e]);
                    w[cnt].erase(end);
                    w[cnt].emplace_front(now);
                    w[d[e]].erase(begin);
                    w[d[e]].emplace_back(e);
                    --b[cnt];
                    ++now;
                }
            }
            minx = 0;
            for (int i = 0; i < l; i++)
                minx = minx * 10 + d[i];
            tmp = n;
            d.clear();
            while (tmp)
            {
                d.emplace_back(tmp % 10);
                tmp /= 10;
            }
            reverse(d.begin(), d.end());
            memset(b, 0, sizeof b);
            for (int i = 0; i < 10; i++)
                w[i].clear();
            for (int i = 0; i < l; i++)
            {
                ++b[d[i]];
                w[d[i]].emplace_back(i);
            }
            now = 0;
            for (int i = 0; i < k; i++)
            {
                if (now >= l)
                    break;
                int cnt = get_max(b);
                if (d[now] == cnt)
                {
                    i -= 1;
                    ++now;
                    --b[cnt];
                    continue;
                }
                deque<int>::iterator end = w[cnt].end() - 1;
                deque<int>::iterator begin = w[d[now]].begin();
                int e = w[cnt].back();
                swap(d[now], d[e]);
                w[cnt].erase(end);
                w[cnt].emplace_front(now);
                w[d[e]].erase(begin);
                w[d[e]].emplace_back(e);
                --b[cnt];
                ++now;
            }
            maxx = 0;
            for (int i = 0; i < l; i++)
                maxx = maxx * 10 + d[i];
            cout << minx << " " << maxx << "\n";
        }
    }
    return 0;
}

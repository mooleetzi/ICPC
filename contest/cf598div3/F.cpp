#include <algorithm>
#include <numeric>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#if __cplusplus >= 201103L
#include <unordered_map>
#include <unordered_set>
#endif
#include <vector>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
#define LONG_LONG_MAX 9223372036854775807LL
#define pblank putchar(' ')
#define ll LL
#define fastIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> P;
int n, m, k;
const int maxn = 2e5 + 10;
template <class T>
inline T read()
{
    int f = 1;
    T ret = 0;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        ret = (ret << 1) + (ret << 3) + ch - '0';
        ch = getchar();
    }
    ret *= f;
    return ret;
}
template <class T>
inline void write(T n)
{
    if (n < 0)
    {
        putchar('-');
        n = -n;
    }
    if (n >= 10)
    {
        write(n / 10);
    }
    putchar(n % 10 + '0');
}
template <class T>
inline void writeln(const T &n)
{
    write(n);
    puts("");
}
template <typename T>
void _write(const T &t)
{
    write(t);
}
template <typename T, typename... Args>
void _write(const T &t, Args... args)
{
write(t), pblank;
 _write(args...);
}
template <typename T, typename... Args>
inline void write_line(const T &t, const Args &... data)
{
   _write(t, data...);
}
inline int lowbit(int x){
    return x & (-x);
}
struct node{
    char ch;
    int id;
    node(){}
    node(char ch,int id){
        this->ch = ch;
        this->id = id;
    }
};
char s1[maxn], s2[maxn];
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r", stdin);
    // freopen("out.txt","w", stdout);
#endif
    fastIO;
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        cin >> s1 >> s2;
        vector<int> num1(26, 0), num2(26, 0);
        for (int i = 0; i < n;i++)
            num1[s1[i] - 'a']++, num2[s2[i] - 'a']++;
        int f = 1;
        for (int i = 0; i < 26;i++)
            if (num1[i]!=num2[i]){
                f = 0;
                break;
            }
            else{
                if (num1[i]>1)
                    f = 2;
            }
        if (!f)
            puts("NO");
        else if (f==2)
            puts("YES");
        else{
            int f1 = 0, f2 = 0;
            for (int i = 0; i < n;i++)
                for (int j = 0; j < i;j++){
                    if (s1[i]>s1[j])
                        ++f1;
                    if (s2[i]>s2[j])
                        ++f2;
                }
            if ((f1+f2)%2==0)
                puts("YES");
            else
                puts("NO");
        }
    }
    return 0;
}
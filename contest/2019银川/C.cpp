/*
 * @Description: In User Settings Editinteresting
 * @Author: your name
 * @Date: 2019-06-27 19:48:56
 * @LastEditTime: 2019-08-31 12:16:36
 * @LastEditors: Please set LastEditors
 */
// #define Local
#define maxn 100005
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define EPS 1e-6
#define ll long long
#define pendl printf("\n")
#define mem0(x) memset(x, 0, sizeof x)
#define mem(x, y) memset(x, y, sizeof x)
#include <algorithm>
#include <assert.h>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
int main()
{
#ifdef Local
    freopen("_data.in", "r", stdin);
    freopen("_data.out", "w", stdout);
#endif
    int kase;
    scanf("%d", &kase);
    for (int tkase = 1; tkase <= kase; tkase++)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        printf("Case #%d: ", tkase);
        char str1[55], str2[55], str3[55];
        scanf("%s%s", str1, str2);
        int gap = str1[0] - str2[0];
        scanf("%s", str3);
        for (int i = 0; i < strlen(str3); i++)
        {
            printf("%c", (str3[i] - 'A' + gap + 26) % 26 + 'A');
        }
        pendl;
    }
}
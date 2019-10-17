#include <bits/stdc++.h>
#define ll long long
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
using namespace std;

char str1[50], str2[50];
char a[50], b[50], c[50];
int solve(char a[])
{
    int k = 50;
    while (k >= 0 && a[k] == 0)
        k--;
    while (k >= 0)
    {
        if (a[k] >= 1)
        {
            while (k - 1 >= 0 && (a[k - 1] >= 1 && a[k] >= 1))
            {
                a[k + 1]++, a[k]--, a[k - 1]--;
                if (a[k] == 0)
                {
                    k--;
                    break;
                }
                else if (a[k - 1] == 0)
                {
                    k -= 2;
                    break;
                }
            }
            if (k - 1 >= 0 && a[k - 1] == 0)
            {
                while (a[k] >= 2)
                {
                    if (k > 1)
                        a[k] -= 2, a[k + 1]++, a[k - 2]++;
                    else if (k == 1)
                        a[k] -= 2, a[k + 1]++, a[k - 1]++;
                    else
                    {
                        k--;
                        break;
                    }
                }
                k--;
            }
            else if (k >= 0)
                k--;
        }
        else
            k--;
    }
    k = 0;
    while (k < 50 && a[k] == 0)
        k++;
    if (k == 0)
    {
        while (a[0] >= 2)
        {
            a[1]++;
            a[0] -= 2;
        }
    }
    while (k < 50)
    {
        if (a[k] >= 1)
        {
            while (k + 1 < 50 && (a[k + 1] >= 1 && a[k] >= 1))
            {
                a[k + 2]++, a[k]--, a[k + 1]--;
                if (a[k] == 0)
                {
                    k++;
                    break;
                }
                else if (a[k + 1] == 0)
                {
                    k += 2;
                    break;
                }
            }
            if (k + 1 <= 50 && a[k + 1] == 0)
            {
                while (a[k] >= 2)
                {
                    if (k > 1)
                        a[k] -= 2, a[k + 1]++, a[k - 2]++;
                    else if (k == 1)
                        a[k] -= 2, a[k + 1]++, a[k - 1]++;
                    else
                    {
                        k++;
                        break;
                    }
                }
                k++;
            }
            else if (k + 1 > 50)
                k++;
        }
        else
            k++;
    }
    k = 50;
    while (k >= 0 && a[k] == 0)
        k--;
    return k;
}

void print(int ka, int shu, int num)
{
    if (num == 1)
        printf("  ");
    if (num == 2)
        printf("+ ");
    if (ka >= 0)
    {
        for (int i = 0; i < shu - ka; i++)
            printf(" ");
        for (int i = ka; i >= 0; i--)
        {
            if (num == 1)
                printf("%d", a[i]);
            else if (num == 2)
                printf("%d", b[i]);
        }
    }
    else
    {
        for (int i = 0; i < shu; i++)
            printf(" ");
        printf("0");
    }
    printf("\n");
}

void print1(int k, int num)
{
    printf("  ");
    if (num >= 0)
    {
        for (int i = num; i >= 0; i--)
        {
            if (k == 1)
                printf("-");
            else
                printf("%d", c[i]);
        }
    }
    else
    {
        if (k == 1)
            printf("-");
        else
            printf("0");
    }
    printf("\n");
    if (k == 2)
        printf("\n");
}

int main()
{
    while (~scanf("%s%s", str1, str2))
    {
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        memset(c, 0, sizeof c);
        int k1 = strlen(str1), k2 = strlen(str2);
        for (int i = 0; i < k1; i++)
            a[i] = str1[k1 - 1 - i] - '0';
        for (int i = 0; i < k2; i++)
            b[i] = str2[k2 - 1 - i] - '0';
        int ka = solve(a);
        int kb = solve(b);
        for (int i = 50; i >= 0; i--)
            c[i] = a[i] + b[i];
        int kc = solve(c);
        int num = max(max(ka, kb), kc);
        print(ka, num, 1);
        print(kb, num, 2);
        print1(1, num);
        print1(2, num);
    }
}
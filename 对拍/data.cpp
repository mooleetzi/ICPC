#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <random>
#include <windows.h>
using namespace std;
//ofstream cout("data.in");
int main()
{
    // freopen("input.txt", "w", stdout);
    srand(time(0));
    const int N = 1000000001;
    mt19937 rand(time(0));
    int n = rand() % 200;
    printf("%d\n", n);
    for (int i = 0; i < n; i++)
    {
        int q = rand() % 100;
        printf("%d\n", q);
        for (int i = 0; i < q; i++)
        {
            int x = rand() % 1000 + 1;
            int y = rand() % 1000 + 1;
            printf("%d %d\n", x, y);
        }
    }
    return 0;
}

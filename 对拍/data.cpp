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
        int x = rand() % (int)(10) + 1;
        int y = rand() % (int)(10) + 1;
        int k = rand() % (int)(10) + 2;
        printf("%d %d %d\n", x, y, k);
    }
    return 0;
}

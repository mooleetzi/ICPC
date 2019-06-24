#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <algorithm>
#include <windows.h>
using namespace std;
//ofstream cout("data.in");
int main()
{
	srand(time(0));
//	srand( (unsigned)time( NULL ) );
	freopen("input.txt","w",stdout);
	int n=rand()%10+1;
    int m = rand() % n + 1;
    printf("%d %d\n",n,m);
	for (int i=1;i<=n;i++){
        for (int j = 1; j <= n;j++)
            printf("%d ", rand() % 10 + 1);
        printf("\n");
    }
    printf("-1 -1");
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(int argc, char const *argv[])
{
    freopen("out.txt","w",stdout);
    srand(time(0));
    int l=0,r=14;
    for (int i=1;i<=100;i++)
        printf("%d\n",rand()%(r-l+1)+l);
    return 0;
}

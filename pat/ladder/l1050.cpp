#include<iostream>
#include<cstdio>
using namespace std;
char ans[7];
int tot=0;
int main(int argc, char const *argv[])
{
    int a[10];
    a[0]=1;
    for (int i=1;i<=6;i++)
        a[i]=a[i-1]*26;
    int l,num;
    scanf("%d%d",&l,&num);
    num=a[l]-num;
    while(num){
        ans[tot++]=num%26+'a';
        num/=26;
    }
    for (int i=tot-1;i>-1;i--)
        printf("%c",ans[i]);
    /* code */
    return 0;
}

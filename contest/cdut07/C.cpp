#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a[10],q=0,mins=0x3f3f3f3f;
        char ch;
        cin>>ch;
        while(ch!='\n'){
            if (ch>='0'&&ch<='9')
                a[q++]=ch-'0';
            ch=cin.get();
        }
        do{
            int t1=0,t2=0;
            for (int i=0;i<q/2;i++)
                t1=t1*10+a[i];
            for (int i=q/2;i<q;i++)
                t2=t2*10+a[i];
            if (abs(t1-t2)<mins)
                mins=abs(t1-t2);
        }while(next_permutation(a,a+q));
        printf("%d\n",mins);
    }
    return 0;
}

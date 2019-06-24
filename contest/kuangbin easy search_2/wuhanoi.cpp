#include<iostream>
#include<cstdio>
int cnt=0;
void move(char a,char c){
//    printf("move from %c to %c\n",a,c);
    ++cnt;
}
void hanoi(int n,char a,char b,char c){
    if (n==1){
        move(a,c);
    }
    else{
        hanoi(n-1,a,c,b);
        move(a,c);
        hanoi(n-1,b,a,c);
    }
}
int main(){
    hanoi(5,'a','b','c');
    printf("%d",cnt);
    return 0;
}

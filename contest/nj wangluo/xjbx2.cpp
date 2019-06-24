#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
int main(){
    char s[100];
    scanf("%s",s);
    char ch;
    int pos,x[100],y[100];
    int c1,c2;
    c1=c2=0;
    for (int i=0;i<strlen(s);i++)
    if (s[i]=='='){
        pos=i;
        break;
    }
    for (int i=0;i<pos;i++){
        if (s[i]>='a'&&s[i]<='z'){
            ch=s[i];
            if (i==0||s[i-1]<48)
                x[c1++]=1;
            else{
                x[c1]=s[i-1]-'0';
                if (i!=1){
                    if (s[i-2]=='-')
                        x[c1]=-x[c1];
                }
                c1++;
            }
        }
        else if (s[i]>='0'&&s[i]<='9'){
            int k=i;
            int p=0;
            while(s[k]>='0'&&s[k]<='9'){
                p=p*10+s[k]-'0';
                k++;
            }
            if (i!=0){
                if (s[i-1]=='-')
                    p=-p;
            }
            if (s[i+1]>='a'&&s[i+1]<='z')
                continue;
            y[c2++]=p;
            i=k;
        }
        else
            continue;
    }
    for (int i=0;i<c1;i++)
        printf("%d ",x[i]);
    printf("\n");
    for (int i=0;i<c2;i++)
        printf("%d ",y[i]);
    return 0;
}

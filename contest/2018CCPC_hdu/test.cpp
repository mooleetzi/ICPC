#include<bits/stdc++.h>
using namespace std;
int judge(int x){
    int m=(int)sqrt(x);
    for (int i=2;i<m+1;i++)
        if (x%i==0)
            return 0;
    return 1;
}
int main(){
    int a[]={1,2,3,4,5,6,7,8,9,10,11,12};
    int ans=0;
    do{
        for (int i=0;i<11;i++)
            if (a[i]==1&&a[i+1]==2)
                ans++;
    }while(next_permutation(a,a+12));
    cout<<ans;
    return 0;
}


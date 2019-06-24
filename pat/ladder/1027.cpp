#include<iostream>
#include<algorithm>
using namespace std;
int b[20];
int a[10];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    string s;
    cin>>s;
    int cnt=0;
    for (auto x:s){
        int now=x-48;
        if (b[now])
            continue;
        b[now]++;
        a[cnt++]=now;
    }
    sort(a,a+cnt,cmp);
    cout<<"int[] arr = new int[]{";
    for (int i=0;i<cnt-1;i++)
        cout<<a[i]<<",";
    cout<<a[cnt-1]<<"};\n";
    cout<<"int[] index = new int[]{";
    int q=0;
    for (auto x:s){
        int now=x-48;
        for (int i=0;i<cnt;i++)
            if (a[i]==now)
                b[q++]=i;
    }
    for (int i=0;i<q-1;i++)
        cout<<b[i]<<",";
    cout<<b[q-1]<<"};";
    return 0;
}

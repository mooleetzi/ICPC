#include<iostream>
#include<string>
using namespace std;
const int maxn=60;
struct node{
    int ind;
    string name;
    node(){}
    node(int x,string a){
        ind=x;
        name=a;
    }
}a[maxn];
int b[maxn];
int main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int x;
        string name;
        cin>>x>>name;
        a[i]=node(x,name);
    }
    for (int i=0;i<n/2-1;i++){
        cout<<a[i].name<<" ";
        int x;
        for (int j=n-1;j>n/2-1;j--)
        if (!b[j]&&a[i].ind!=a[j].ind){
            x=j;
            break;
        }
        b[x]=1;
        cout<<a[x].name<<"\n";
    }
    cout<<a[n/2-1].name<<" ";
    for (int i=n/2;i<n;i++)
    if (!b[i]){
        cout<<a[i].name;
        break;
    }
    return 0;
}

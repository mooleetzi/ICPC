#include<bits/stdc++.h>
using namespace std;
struct node{
    int math,chin,eng,ind,all;
    node(){}
    node(int i,int c,int m,int e){
        ind=i;
        math=m;
        chin=c;
        eng=e;
        all=math+chin+eng;
    }
    bool operator<(const node&a)const{
        if (all==a.all){
            if (chin==a.chin)
                return ind<a.ind;
            return chin>a.chin;
        }
        return all>a.all;
    }
};
vector<node> a;
int main(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        int x,y,z;
        cin>>x>>y>>z;
        a.emplace_back(node(i,x,y,z));
    }
    sort(a.begin(),a.end());
    for (int i=0;i<5;i++)
        cout<<a[i].ind<<" "<<a[i].all<<"\n";
    return 0;
}

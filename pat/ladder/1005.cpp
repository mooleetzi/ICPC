#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct node{
    string first;
    int n,m;
    node(string s,int x,int y){
        first=s;
        n=x;
        m=y;
    }
    node(){}
};
vector<node> a;
int main(){
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n;
    for (int i=0;i<n;i++){
        string s;
        int x,y;
        cin>>s>>x>>y;
        a.emplace_back(node(s,x,y));
    }
    cin>>m;
    for (int i=0;i<m;i++){
        int k;
        cin>>k;
        for (int j=0;j<n;j++)
        if (a[j].n==k){
            cout<<a[j].first<<" "<<a[j].m;
            if (i<m-1)
                cout<<"\n";

        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
vector<int> v1,v2;
int main(){
    v1.clear();
    v2.clear();
    int n,m;
    scanf("%d%d",&n,&m);
    v1.push_back(0);
    for (int i=1;i<=n;i++)
        v1.push_back(i);
    for (int i=0;i<m;i++){
        int a,b;
        v2.clear();
        v2.push_back(0);
        scanf("%d%d",&a,&b);
        for (int j=a;j<=a+b-1;j++)
            v2.push_back(v1[j]);
        for (int j=1;j<a;j++)
            v2.push_back(v1[i]);
        for (int j=a+b;j<=n;j++)
            v2.push_back(v1[i]);
        v1.clear();
        v1.push_back(0);
        v1.assign(v2.begin(),v2.end());
    }
    for (int i=1;i<=n;i++)
        scanf("%d ",v2[i]);
    return 0;
}

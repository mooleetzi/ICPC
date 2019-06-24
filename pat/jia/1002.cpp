#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#define eps 0.0000001
using namespace std;
struct node{
    int e;
    double k;
    node(){}
    node(int x,double y):e(x),k(y){}
    bool operator<(const node&a)const{
        return e>a.e;
    }
};
vector<node> s1,s2,s3;
int main(){
//    ios::sync_with_stdio(false);
    int n,m;
    scanf("%d",&n);
    while(n--){
        int e;
        double k;
        scanf("%d%lf",&e,&k);
        s1.emplace_back(node(e,k));
    }
    cin>>m;
    while(m--){
        int e;
        double k;
        scanf("%d%lf",&e,&k);
        s2.emplace_back(node(e,k));
    }
    for (int i=0;i<s1.size();i++){
        int flag=0;
        for (vector<node>::iterator it=s2.begin();it!=s2.end();it++){
            if(s1[i].e==it->e){
                s3.emplace_back(node(it->e,it->k+s1[i].k));
                it=s2.erase(it);
                flag=1;
                if (s2.empty())
                    break;
                it--;
            }
        }
        if (!flag)
            s3.emplace_back(s1[i]);
    }
    for (vector<node>::iterator it=s2.begin();it!=s2.end();it++)
        s3.emplace_back(*it);
    for (vector<node>::iterator it=s3.begin();it!=s3.end();it++)
    if (fabs(it->k)<eps){
        it=s3.erase(it);
        if (s3.empty())
            break;
        it--;
    }
    sort(s3.begin(),s3.end());
    if (s3.size()==0){
        cout<<0;
        return 0;
    }
    cout<<s3.size()<<" ";
    for (int i=0;i<s3.size()-1;i++)
        printf("%d %.1f ",s3[i].e,s3[i].k);
    printf("%d %.1f",s3[s3.size()-1].e,s3[s3.size()-1].k);
    return 0;
}

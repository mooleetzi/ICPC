#include<iostream>
#include<set>
#include<cmath>
#include<vector>
#include<map>
#include<cstdlib>
#include<ctime>
using namespace std;
const int maxn=1e5+10;
struct node{
    string now,next;
    int key;
    node(){}
    node(string s1,int n,string s2){
        now=s1;
        key=n;
        next=s2;
    }
    bool operator==(const node&a)const{
        return now==a.now&&key==a.key&&next==a.next;
    }
    bool operator!=(const node&a)const{
        return !(*this==a);
    }
    bool operator<(const node&a)const{
        return key<a.key;
    }
}tmp[maxn];
set<int> ss;
vector<node> a,b;
typedef pair<string,int> pa;
map<string,int> mm;
set<node> my;
int main(){
    int n;
    string first;
    cin>>first>>n;
    node q;
    for (int i=1;i<=n;i++){
        cin>>tmp[i].now>>tmp[i].key>>tmp[i].next;
        if (tmp[i].now==first||!ss.count(abs(tmp[i].key))){
            my.insert(tmp[i]);
            ss.insert(abs(tmp[i].key));
            mm.insert(pa(tmp[i].now,i));
            if (tmp[i].now==first){
                q=tmp[i];
            }
        }
    }
    while(q.next!="-1"){
        cout<<q.now<<" "<<q.key<<" "<<q.next<<"\n";
        int n=mm[q.next];
        q=tmp[n];
    }
    cout<<q.now<<" "<<q.key<<" "<<-1<<"\n";
    return 0;
}

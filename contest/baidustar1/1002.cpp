#include<bits/stdc++.h>
#include<ext/rope>
using namespace std;
using namespace __gnu_cxx;
const int maxn=150005;
const int maxq=400010;
void read(int &x){
	char ch = getchar();x = 0;
	for (; ch < '0' || ch > '9'; ch = getchar());
	for (; ch >='0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
}
int n,q;
vector<rope<int> > deq;
vector<rope<int> > de;
int main(){
    ios::sync_with_stdio(false);
    while(cin>>n>>q){
        rope<int> now;
        deq.push_back(now);
        de.push_back(now);
        for (int i=1;i<=n;i++)
            deq.push_back(now),de.push_back(now);
        for (int i=1;i<=q;i++){
            int a,b,c,d;
            read(a);
            if (a==1){
                read(b);
                read(c);
                read(d);
                int l=deq[b].size();
                if (c==0){
                    deq[b].insert(0,d);
                    de[b].push_back(d);
                }
                else if (c==1){
                    deq[b].push_back(d);
                    de[b].insert(0,d);
                }
            }
            else if (a==2){
                read(b);
                read(c);
                int ans=-1;
                int l=deq[b].size();
                if (l!=0){
                    if (c==0){
                        ans=deq[b][0];
                        deq[b].erase(0,1);
                        de[b].erase(l-1,1);
                    }
                    else{
                        ans=deq[b][l-1];
                        deq[b].erase(l-1,1);
                        de[b].erase(0,1);
                    }
                }
                printf("%d\n",ans);
            }
            else if (a==3){
                read(b),read(c),read(d);
                int l1=deq[b].size();
                int l2=deq[c].size();
                if (d==0){
                    deq[b]=deq[b].substr(0,l1)+deq[c].substr(0,l2);

                }
                else if (d==1){
                    deq[b]=deq[b].substr(0,l1)+de[c].substr(0,l2);
                }
                deq[c].clear();
                de[c].clear();
            }
        }
    }
    return 0;
}

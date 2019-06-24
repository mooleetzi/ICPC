#include<bits/stdc++.h>
using namespace std;
const int maxn=150005;
const int maxq=400010;
void read(int &x){
	char ch = getchar();x = 0;
	for (; ch < '0' || ch > '9'; ch = getchar());
	for (; ch >='0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
}
int n,q;;
int main(){
    //cin.tie(0);
    while(cin>>n>>q){
        deque<int> deq[n+2];
        for (int i=1;i<=q;i++){
            int a,b,c,d;
            read(a),read(b),read(c);
            if (a==1){
                read(d);
                if (c==0){
                    deq[b].push_front(d);
                }
                else if (c==1){
                    deq[b].push_back(d);
                }
            }
            else if (a==2){
                int ans=-1;
                if (!deq[b].empty()){
                    if (c==0){
                        ans=deq[b].front();
                        deq[b].pop_front();
                    }
                    else{
                        ans=deq[b].back();
                        deq[b].pop_back();
                    }
                }
                cout<<ans<<"\n";
            }
            else if (a==3){
                read(d);
                if (d==0){
                    for (deque<int>::iterator it=deq[c].begin();it!=deq[c].end();it++)
                        deq[b].push_back(*it);
                }
                else if (d==1){
                    for (deque<int>::reverse_iterator it=deq[c].rbegin();it!=deq[c].rend();it++)
                        deq[b].push_back(*it);
                }
                deq[c].clear();
            }
        }
    }
    return 0;
}

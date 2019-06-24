#include<bits/stdc++.h>
using namespace std;
vector<int> a,b,c,d;
set<int> s;
int ans=0;
int main(){
    a.push_back(-1);
    a.push_back(0);
    a.push_back(1);
    a.push_back(1);
    b.assign(a.begin(),a.end());
    c.assign(a.begin(),a.end());
    d.assign(a.begin(),a.end());
    do{
        do{
            do{
                do{
                    ans++;
                    s.clear();
                    vector<vector<int> > now;
                    now.push_back(a);
                    now.push_back(b);
                    now.push_back(c);
                    now.push_back(d);
                    int q=0;
                    for (auto x:now[0])
                        q+=x;
                    s.insert(q);
                    q=0;
                    for (auto x:now[1])
                        q+=x;
                    s.insert(q);
                    q=0;
                    for (auto x:now[2])
                        q+=x;
                    s.insert(q);
                    q=0;
                    for (auto x:now[3])
                        q+=x;
                    s.insert(q);
                    q=0;
                    for (int i=0;i<4;i++)
                        q+=now[i][0];
                    s.insert(q);
                    q=0;
                    for (int i=0;i<4;i++)
                        q+=now[i][1];
                    s.insert(q);
                    q=0;
                    for (int i=0;i<4;i++)
                        q+=now[i][2];
                    s.insert(q);
                    q=0;
                    for (int i=0;i<4;i++)
                        q+=now[i][3];
                    s.insert(q);
                    if (s.size()==8){
                        for (int i=0;i<4;i++){
                            for (int j=0;j<4;j++)
                                cout<<now[i][j]<<" ";
                            cout<<"\n";
                        }
                }
                }while(next_permutation(d.begin(),d.end()));
            }while(next_permutation(c.begin(),c.end()));
        }while(next_permutation(b.begin(),b.end()));
    }while(next_permutation(a.begin(),a.end()));
    cout<<ans;
}

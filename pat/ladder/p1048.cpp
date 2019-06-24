#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
vector<vector<int> >a,b;
void mulity(vector<vector<int> >a,int ra,int ca,vector<vector<int> >b,int rb,int cb){
    if (ca!=rb){
        cout<<"Error: "<<ca<<" != "<<rb<<"\n";
        return;
    }
    int c[ra][cb];
    memset(c,0,sizeof c);
    for (int i=0;i<ra;i++)
    for (int j=0;j<cb;j++){
        int now=0;
        for (int k=0;k<ca;k++)
            now+=a[i][k]*b[k][j];
        c[i][j]=now;
    }
    cout<<ra<<" "<<cb<<"\n";
    for (int i=0;i<ra;i++){
        for (int j=0;j<cb-1;j++)
            cout<<c[i][j]<<" ";
        cout<<c[i][cb-1]<<"\n";
    }
}
int main(){
    int ra,ca,rb,cb;
    cin>>ra>>ca;
    for (int i=0;i<ra;i++){
        vector<int> cur;
        for (int j=0;j<ca;j++){
            int x;
            cin>>x;
            cur.push_back(x);
        }
        a.push_back(cur);
    }
    cin>>rb>>cb;
    for (int i=0;i<rb;i++){
        vector<int>cur;
        for (int j=0;j<cb;j++){
            int x;
            cin>>x;
            cur.push_back(x);
        }
        b.push_back(cur);
    }
    mulity(a,ra,ca,b,rb,cb);
    return 0;
}

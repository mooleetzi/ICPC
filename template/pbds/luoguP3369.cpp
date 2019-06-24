#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
using pa=pair<int,int>;
typedef tree<pa,null_type,less<pa>,rb_tree_tag,tree_order_statistics_node_update> rbTree;
rbTree tr;
gp_hash_table<int,int> h;
int main(){
    int n;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    while(n--){
        int op,x;
        cin>>op>>x;
        if (op==1)
            tr.insert(pa(x,++h[x]));
        else if (op==2)
            tr.erase(pa(x,h[x]--));
        else if (op==3)
            cout<<tr.order_of_key(pa(x,0))+1<<"\n";
        else if (op==4)
            cout<<tr.find_by_order(x-1)->first<<"\n";
        else if (op==5)
            cout<<tr.find_by_order( tr.order_of_key ( pa( x , 0 ) )-1 )->first<<"\n";
        else if (op==6)
            cout<<tr.upper_bound(pa(x,INT_MAX))->first<<"\n";
    }
    return 0;
}

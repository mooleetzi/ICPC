#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
const int maxn = 1e3 + 10;
int n;
struct node
{
    int x, y,idx;
    node(){}
    node(int a,int b,int i):x(a),y(b),idx(i){}
    bool operator<(const node &a)const{
        if (x==a.x)
            return y < a.y;
        return x < a.x;
    }
}a[maxn*3];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 1; i <= 3 * n;i++){
            int x, y;
            cin >> x >> y;
            a[i] = node(x, y, i);
        }
        sort(a + 1, a + 1 + 3 * n);
        for (int i = 1; i <= n;i++){
            int tmp = 3 * (i - 1);
            cout << a[tmp+1].idx << " " << a[tmp + 2].idx << " " << a[tmp + 3].idx << "\n";
        }
    }
    return 0;
}

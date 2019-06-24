#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef pair<int, int> pa;
map<int, int> ma1,ma2;
struct node
{
    int index, num;
    node(){}
    node(int x,int y){
        index = x;
        num = y;
    }
    bool operator<(const node &a)const{
        return num < a.num;
    }
    /* data */
};

priority_queue<node> que1, que2;
vector<int> c, r;
int cc[1100], rr[1100];
int main(int argc, char const *argv[])
{
    int n, m, k, l, d;
    cin >> n >> m >> k >> l >> d;
    for (int i = 0; i < d;i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1==x2)
            ma2[min(y1, y2)]++;
        if (y1 == y2)
            ma1[min(x1, x2)]++;
    }
    for (auto x:ma1)
        que1.push(node(x.first,x.second));
    for (auto x:ma2)
        que2.push(node(x.first,x.second));
    for (int i = 0; i < k; i++)
    {
        if (que1.empty())
            break;
        c.push_back(que1.top().index);
        que1.pop();
    }
    for (int i = 0; i < l;i++){
        if (que2.empty())
            break;
        r.push_back(que2.top().index);
        que2.pop();
    }
    sort(c.begin(), c.end());
    sort(r.begin(), r.end());
    for (int i = 0; i < c.size() - 1; i++)
        cout << c[i] << " ";
    cout << c.back() << "\n";
    for (int i = 0; i < r.size() - 1;i++)
        cout << r[i] << " ";
    cout << r.back();
    /* code */
    return 0;
}

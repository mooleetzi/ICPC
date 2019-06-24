#include<iostream>
#include<queue>
#include<set>
using namespace std;
set<int> s;
queue<int> que;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> m >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (!s.count(x)){
            if (s.size()==m){
                int out = que.front();
                s.erase(out);
                que.pop();
                que.push(x);
                s.insert(x);
            }
            else
            {
                s.insert(x);
                que.push(x);
            }
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
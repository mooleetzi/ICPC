#include<bits/stdc++.h>
using namespace std;
using pa = pair<char, int>;
const int maxn=1100;
set<char> s;
deque<pa> que;
int getNum(char s[]){
    int ans = 0;
    for (int i = 0; i < strlen(s);i++){
        if (s[i]==')')
            break;
        ans = ans * 10 + s[i] - 48;
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--){
        int n;
        char ss[10];
        que.clear();
        s.clear();
        cin >> n >> ss;
        int flag = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            char op;
            cin >> op;
            if (op=='F'){
                char j;
                char x[5], y[5];
                cin >> j >> x >> y;
                if (s.count(j)){
                    flag = 1;
                }
                s.insert(j);
                if ((x[0]=='n'&&y[0]!='n')||(getNum(x)>getNum(y)&&y[0]!='n')){
                    que.push_back(pa(j, 0));//O(1),内部不考虑
                }
                else if (getNum(x)<100&&y[0]=='n'&&x[0]!='n')
                {
                    // cout << "yes it is\n";
                    que.push_back(pa(j, 1)); //O(n)
                }
                else if ((getNum(x)<=getNum(y)&&y[0]!='n'&&x[0]!='n')||(x[0]==y[0]&&x[0]=='n'))
                {
                    que.push_back(pa(j, 2));//O(1)，内部需要考虑
                }
            }
            else
            {
                int tmp = 0;
                for (auto x : que)
                {
                    if (x.second==1)
                        ++tmp;
                    else if (x.second==0)
                    {
                        break;
                    }
                    else if (x.second==2)
                    {
                        continue;
                    }
                }
                ans = max(ans, tmp);
                if (que.empty()){
                    flag = 1;
                }
                else
                {
                    s.erase(que.back().first);
                    que.pop_back();
                }
            }
        }
        if (flag||!que.empty())
            printf("ERR\n");
        else if (getNum(ss+4)==ans||(ss[strlen(ss)-2]=='1'&&ans==0&&strlen(ss)==4))
        {
            printf("Yes\n");
        }
        else
        {
            // cout << ans << "\n";
            printf("No\n");
        }
    }
    return 0;
}

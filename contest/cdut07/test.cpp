
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

typedef pair<string, int> P;

const int INF = 100000000;

//输入
string a;

//移动方向
int op[4] = {-1, 1, -4, 4};

map<string, int> dp;                        //保存从string变到"01234567"的int

//计算从"01234567"转换到其他序列所需的最小步数
void bfs(){
    //初始化
    queue<P> que;
    que.push(P("01234567", 0));
    dp["01234567"] = 0;
    //宽度优先搜索
    while(!que.empty()){
        P p = que.front();
        que.pop();
        string s = p.first;
        int cur = p.second;
        for(int i = 0; i < 4; i ++){
            //构造下一次交换
            int next = cur + op[i];
            string str = s;
            swap(str[cur], str[next]);
            map<string, int>::iterator it = dp.find(str);
            //判断是否可移动以及是否访问过
            if(0 <= next && next < 8
                && !(cur == 3 && next == 4) && !(cur == 4 && next == 3)
                && it == dp.end()){

                que.push(P(str, next));
                dp[str] = dp[s] + 1;
            }
        }
    }
}

void solve(){
    //删除空格
    a.erase(remove(a.begin(), a.end(), ' '), a.end());
    cout<<dp[a]<<endl;
}

int main(int argc, char const *argv[]){
    //先逆向构造所有情况，后直接读取输入用例的结果
    bfs();
    while(getline(cin, a)){
        solve();
    }
    return 0;
}

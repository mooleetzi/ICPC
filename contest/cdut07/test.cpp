
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

typedef pair<string, int> P;

const int INF = 100000000;

//����
string a;

//�ƶ�����
int op[4] = {-1, 1, -4, 4};

map<string, int> dp;                        //�����string�䵽"01234567"��int

//�����"01234567"ת�������������������С����
void bfs(){
    //��ʼ��
    queue<P> que;
    que.push(P("01234567", 0));
    dp["01234567"] = 0;
    //�����������
    while(!que.empty()){
        P p = que.front();
        que.pop();
        string s = p.first;
        int cur = p.second;
        for(int i = 0; i < 4; i ++){
            //������һ�ν���
            int next = cur + op[i];
            string str = s;
            swap(str[cur], str[next]);
            map<string, int>::iterator it = dp.find(str);
            //�ж��Ƿ���ƶ��Լ��Ƿ���ʹ�
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
    //ɾ���ո�
    a.erase(remove(a.begin(), a.end(), ' '), a.end());
    cout<<dp[a]<<endl;
}

int main(int argc, char const *argv[]){
    //�������������������ֱ�Ӷ�ȡ���������Ľ��
    bfs();
    while(getline(cin, a)){
        solve();
    }
    return 0;
}

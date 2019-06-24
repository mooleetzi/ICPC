// #include<bits/stdc++.h>
#include<iostream>
#include<deque>
#include<vector>
using namespace std;
const int maxn = 1e6 + 10;
int n,k;
struct node{
    int x, idx;
    node(){}
    node(int a,int b):x(a),idx(b){}
};
deque<node> q1,q2;
vector<int> ans1, ans2;
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n;i++){
        int x;
        cin >> x;
        while(!q1.empty()&&q1.back().x>x)
            q1.pop_back();
        q1.push_back(node(x,i));
        while(!q1.empty()&&i-q1.front().idx>=k)
            q1.pop_front();
        while(!q2.empty()&&q2.back().x<x)
            q2.pop_back();
        while(!q2.empty()&&i-q2.front().idx>=k)
            q2.pop_front();
        q2.push_back(node(x,i));
        if (i>=k)
            ans1.push_back(q1.front().x), ans2.push_back(q2.front().x);
    }
    for (int i = 0; i < ans1.size();i++)
        cout << ans1[i] << " ";
    cout << "\n";
    for (int i = 0; i < ans2.size();i++)
        cout << ans2[i] << " ";
    cout << "\n";
    return 0;
}

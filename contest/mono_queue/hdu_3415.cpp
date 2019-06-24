/*
    单调队列
        a[i]表示前缀和
        单调队列以递减保存前缀和
        答案更新条件为 a[i]-q.front().first>ans
        tips:
            由于sum[i,j]=a[j]-a[i-1],单调队列每次push的应当是a[i-1],且pop_front()条件应为i-q.front().second>k而非>=
*/
#include<bits/stdc++.h>
using namespace std;
using pa = pair<int, int>;
using ll = long long;
const int maxn = 2e5 + 10;
int n,k;
int a[maxn];
deque<pa> q;
int dp[maxn];
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        q.clear();
        cin >> n >> k;
        int l, r;
        int ans = -1e9;
        for (int i = 1; i <= n;i++)
            cin >> a[i], a[i] += a[i - 1];
        for (int i = n + 1; i <= n + k-1;i++)
            a[i] = a[i - n] + a[n];
        for (int i = 1; i <= n+k-1;i++){
            while(!q.empty()&&q.back().first>a[i-1])
                q.pop_back();
            q.push_back(pa(a[i - 1], i - 1));
            while(!q.empty()&&i-q.front().second>k)
                q.pop_front();
            int sum = a[i] - q.front().first;
            if (sum>ans){
                ans = sum;
                l = q.front().second+1;
                r = i;
                if (r>n)
                    r -= n;
            }
        }
        cout << ans << " " << l << " " << r << "\n";
    }
    return 0;
}


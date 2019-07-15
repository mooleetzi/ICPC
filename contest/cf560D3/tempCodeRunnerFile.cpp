/*
    一个数等于所有非1和自身的除数的最小值*最大值
 */
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
using ull = unsigned long long;
const int maxn = 320;
vector<ull> vec;
int n;
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        vec.clear();
        cin >> n;
        for (int i = 0; i < n;i++){
            int x;
            cin >> x;
            vec.push_back(x);
        }
        sort(vec.begin(), vec.end());
        ull t = vec.front() * vec.back();
        vector<ull> v2;
        v2.clear();
        for (ull i = 2; i <= sqrt(t) + 1;i++)
            if (t%i==0){
                v2.emplace_back(i);
                if (i!=t/i)
                    v2.emplace_back(t / i);
            }
        sort(v2.begin(), v2.end());
        if (v2==vec)
            cout << t << "\n";
        else
            cout << "-1\n";
    }
    return 0;
}

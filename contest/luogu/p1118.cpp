#include<bits/stdc++.h>
using namespace std;
const int maxn = 15;
int n;
int yh[maxn][maxn];
int getSum(vector<int> a)
{
    int sum = 0;
    for (int i = 0; i < a.size(); i++)
    {
        sum += a[i] * yh[n][i+1];
    }
    return sum;
}
int main(int argc, char const *argv[])
{
    int k;
    cin >> n >> k;
    vector<int> a;
    yh[1][1] = 1;
    for (int i = 2; i <= n; i++) //构造杨辉三角
        for (int j = 1; j <= i; j++)
            yh[i][j] = yh[i - 1][j - 1] + yh[i - 1][j];
    for (int i = 1; i <= n;i++)
        a.emplace_back(i);
    do{
        if (getSum(a)==k){
            for (int x:a)
                cout << x << " ";
            cout << "\n";
            break;
        }

    } while (next_permutation(a.begin(),a.end()));
    return 0;
}

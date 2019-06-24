#include<bits/stdc++.h>
using namespace std;
map<string, int> ma;
map<int, string> ma2;
int a[12][2];
int n;
int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 1; i <= n;i++){
        string s;
        cin >> s;
        ma[s] = i;
        ma2[i] = s;
    }
    for (int i = 1; i <= n;i++){
        string s;
        cin >> s;
        int pre, to;
        cin >> pre >> to;
        for (int j = 0; j < to;j++){
            string s1;
            cin >> s1;
            a[ma[s1]][1] += pre / to;
        }
        if (to)
            a[ma[s]][0] = pre-pre % to;
        else
        {
            a[ma[s]][0] = pre;
        }
    }
    for (int i = 1; i <= n;i++)
        cout << ma2[i]<<" "<<a[i][1] - a[i][0]<<"\n";
    return 0;
}


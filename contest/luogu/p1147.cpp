#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 10;
int m;
int isok(int x)
{
    int delta = (2 * x - 1) * (2 * x - 1) + 8 * m;
    int tmp = (sqrt(delta) - 2 * x + 1) / 2;
    if (tmp*tmp+(2*x-1)*tmp==2*m)
        return tmp;
    return 0;
}
int main(){
    cin >> m;
    for (int i = 1; i <=m/2;i++){
        int tmp = isok(i);
        if (tmp)
            cout << i << " " << i + tmp - 1 << "\n";
    }
    return 0;
}
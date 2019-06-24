#include<bits/stdc++.h>
using namespace std;
int n, l, g;
int main(int argc, char const *argv[])
{
    cin >> n >> l >> g;
    for (int i = 1; i <= n;i++){
        int x, y;
        cin >> x >> y;
        while(x>g||y>g){
            x >>= 1;
            y >>= 1;
        }
        if (x<l||y<l)
            cout << "Too Young\n";
        else if (x!=y)
            cout << "Too Simple\n";
        else
        {
            cout << "Sometimes Naive\n";
        }
        }
    return 0;
}

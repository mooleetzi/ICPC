#include<bits/stdc++.h>
using namespace std;
double lagrange(vector<double> x,vector<double> y,double xx){
    double ans = 0;
    for (int i = 0; i < x.size();i++){
        double t0 = 1,t1=1;
        for (int j = 0; j < x.size();j++)
            if (i!=j)
                t0 *= (x[i] - x[j]), t1 *= (xx - x[j]);
        ans += t1 / t0 * y[i];
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    vector<double> xx, yy;
    for (int i = 0; i < n;i++){
        double x0,y0;
        cin >> x0>>y0;
        xx.push_back(x0);
        yy.push_back(y0);
    }
    double x;
    cin >> x;
    cout << lagrange(xx, yy, x);
    return 0;
}

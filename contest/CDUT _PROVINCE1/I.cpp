#include<bits/stdc++.h>
using namespace std;
typedef vector<double> node;
struct tet
{
    vector<node> v;
    tet(){}
    tet(const vector<double> &a){
        node now;
        for (int i = 1; i <= 12;i++){
            now.emplace_back(a[i - 1]);
            if (i%3==0){
                v.emplace_back(now);
                now.clear();
            }
        }
    }
    double len(node x1,node x2){
        return sqrt((x1[0] - x2[0]) * (x1[0] - x2[0]) + (x1[1] - x2[1]) * (x1[1] - x2[1]) + (x1[2] - x2[2]) * (x1[2] - x2[2]));
    }
    int isSphere(){
        for (int i = 0; i < v.size();i++)
            for (int j = i + 1; j < v.size();j++)
                for (int k = j + 1; k < v.size();k++){
                    if (!judge(len(v[i],v[j]),len(v[i],v[k]),len(v[k],v[j])))
                        return false;
                }
        return true;
    }
    int judge(double x,double y,double z){
        vector<double> now;
        now.emplace_back(x), now.emplace_back(y), now.emplace_back(z);
        sort(now.begin(), now.end());
        return now[0] + now[1] > now[2];
    }
};
int main(int argc, char const *argv[])
{
    int t;
    double x;
    node now;
    while(cin>>x){
        now.emplace_back(x);
        if (now.size()==12){
            tet q(now);
            now.clear();
            if (!q.isSphere()){
                cout << "0 0 0 0\n";
            }
            else{
                cout << "yes\n";
            }
        }
    }
    return 0;
}

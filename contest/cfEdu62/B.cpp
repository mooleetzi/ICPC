#include<bits/stdc++.h>
using namespace std;
const int maxn = 110;
// int getAns(string s){
//     stack<char> st;
//     int ans = 0;
//     while (!st.empty())
//         st.pop();
//     for (auto x:s){
//         if (x=='<')
//             st.push(x);
//         else{
//             if (!st.empty()){
//                 ++ans;
//                 st.pop();
//             }
//         }
//     }
//     return ans;
// }
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (s.front()=='>'||s.back()=='<')
            cout << "0\n";
        else
        {
            int a1 = 0, a2 = 0;
            string tmp = s;
            while(tmp.front()!='>'&&tmp.size()){
                tmp.erase(tmp.begin());
                ++a1;
            }
            tmp = s;
            while(tmp.back()!='<'&&tmp.size()){
                tmp.erase(tmp.end()-1);
                ++a2;
            }
            cout << min(a1, a2) << "\n";
        }
    }
    return 0;
}

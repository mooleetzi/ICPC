#include<iostream>
#include<vector>
using namespace std;
vector<string> now;
int main(){
    string s;
    while(1){
        cin>>s;
        if (s==".")
            break;
        now.push_back(s);
    }
    if (now.size()<2)
        cout<<"Momo... No one is for you ...\n";
    else if (now.size()<14)
        cout<<now[1]<<" is the only one for you...\n";
    else
        cout<<now[1]<<" and "<<now[13]<<" are inviting you to dinner...\n";
    return 0;
}

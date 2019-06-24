#include<iostream>
using namespace std;
int g,p,l,t;
int main(){
    string s;
    cin>>s;
    for (int i=0;i<s.size();i++)
        if (s[i]=='G'||s[i]=='g')
            ++g;
        else if(s[i]=='P'||s[i]=='p')
            ++p;
        else if (s[i]=='L'||s[i]=='l')
            ++l;
        else if (s[i]=='T'||s[i]=='t')
            ++t;
    while(g||p||l||t){
        if (g){
            cout<<"G";
            --g;
        }
        if (p){
            cout<<"P";
            --p;
        }
        if (l){
            cout<<"L";
            --l;
        }
        if (t){
            cout<<"T";
            --t;
        }
    }
    return 0;
}

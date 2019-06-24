#include<iostream>
#include<set>
#include<vector>
inline int read(){
    int tmp=0;
    char ch;
    int f=1;
    ch=getchar();
    if(ch=='-'){
        ch=getchar();
        f=-1;
    }
    while(ch>='0'&&ch<='9'){
        tmp=tmp*10+ch-'0';
        ch=getchar();
    }
    return tmp*f;
}
using namespace std;
vector<set<int>> s;
int main(int argc, char const *argv[])
{
    int n;
    // n=read();
    cin>>n;
    for (int i=0;i<n;i++){
        set<int> ss;
        ss.clear();
        // int now=read();
        int now;
        cin>>now;
        for (int i=0;i<now;i++){
            int x;
            cin>>x;
            ss.insert(x);
        }
        s.push_back(ss);
    }
    // n=read();
    cin>>n;
    for (int i=0;i<n;i++){
        // int l=read(),r=read();
        int l,r;
        cin>>l>>r;
        set<int> s1=s[l-1];
        set<int> s2=s[r-1];
        int nc=0,nt=0;
        for (auto x:s1){
            if (s2.count(x))
                nc++;
        }
        set<int> s3=s1;
        s3.insert(s2.begin(),s2.end());
        nt=s3.size();
        printf("%.2f%\n",nc*1.0/nt*100);

    }
    return 0;
}

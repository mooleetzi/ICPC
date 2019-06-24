#include<iostream>
using namespace std;
int b[1010];
int main(){
    int n;
    cin>>n;
    int ans=0;
    for (int i=0;i<n;i++){
        int now;
        cin>>now;
        for (int i=0;i<now;i++){
            int x;
            cin>>x;
            ++b[x];
            if (b[x]>b[ans])
                ans=x;
            else if (b[x]==b[ans]&&x>ans)
                ans=x;
        }
    }
    cout<<ans<<" "<<b[ans];
    return 0;
}

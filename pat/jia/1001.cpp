#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int n,m,sum;
    cin>>n>>m;
    sum=n+m;
    vector<char> ans;
    ans.clear();
    if (sum<0){
        cout<<"-";
        sum=-sum;
    }
    else if (sum==0||sum<10){
        cout<<sum;
        return 0;
    }
    int tmp=sum;
    while(sum){
        ans.push_back((sum%10)+48);
        sum/=10;
    }
    reverse(ans.begin(),ans.end());
    if (ans.size()<=3){
        cout<<tmp;
        return 0;
    }
    if (ans.size()%3==0){
        int j;
        for (j=0;j+2<ans.size();j+=3){
            cout<<ans[j]<<ans[j+1]<<ans[j+2];
            if (j+3==ans.size())
                continue;
            else
                cout<<",";
        }
    }
    else if (ans.size()%3==1){
        int j;
        cout<<ans[0]<<",";
        for (j=1;j+2<ans.size();j+=3){
            cout<<ans[j]<<ans[j+1]<<ans[j+2];
            if (j+3==ans.size())
                continue;
            else
                cout<<",";
        }
    }
    else if (ans.size()%3==2){
        int j;
        cout<<ans[0]<<ans[1]<<",";
        for (j=2;j+2<ans.size();j+=3){
            cout<<ans[j]<<ans[j+1]<<ans[j+2];
            if (j+3==ans.size())
                continue;
            else
                cout<<",";
        }
    }
    return 0;
}

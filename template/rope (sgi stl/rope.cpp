#include<bits/stdc++.h>
#include<ext/rope>
using namespace std;
using namespace __gnu_cxx;
rope<int> info,t;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        info.push_back(i);
    for (int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        info=info.substr(a-1,b)+info.substr(0,a-1)+info.substr(a+b-1,n-a-b+1);
    }
    for (auto x : info)
        printf("%d ",x);
    return 0;
}
/*
ͷ�ļ� ext/rope
���ռ� __gnu_cxx
����һ�ſɳ�����ƽ���� rope<type> name
����
 name.push_back(i) ��β������i
 name.insert(pos,x) ��λ��pos����x
 name.erase(pos,x) ��λ��pos��ʼɾ��x��Ԫ��
 name.replace(pos,x) ��λ��pos��Ԫ���û�Ϊx
 name.substr(pos,x) ��λ��pos����ȡx��������һ����rope
���е�
 rope֧��+����
*/

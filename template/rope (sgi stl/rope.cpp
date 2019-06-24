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
头文件 ext/rope
名空间 __gnu_cxx
定义一颗可持续化平衡树 rope<type> name
操作
 name.push_back(i) 在尾部插入i
 name.insert(pos,x) 在位置pos插入x
 name.erase(pos,x) 从位置pos开始删除x个元素
 name.replace(pos,x) 将位置pos处元素置换为x
 name.substr(pos,x) 从位置pos出提取x个，返回一个子rope
还有点
 rope支持+操作
*/

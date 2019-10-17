/*
    块状链表,可持久化数组，superString
    整体复杂度O(n^1.5)
*/
#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
rope<typename> r, *f[1010];

r.length() / r.size();           //返回x的大小
r.push_back(s);                  //在末尾添加s
r.insert(pos, s);                //在pos位置插入s
r.erase(pos, x);                 //从pos位置开始删除x个;
r.replace(pos, s);               //将位置为pos的元素换成s
r.substr(pos, x);                //从pos位置开始提取x个元素
r.copy(pos, x, s);               //将从pos位置开始x个元素提取到s中
r.at(x) / [x];                   //访问第x个元素
f[i] = new rope<int>(*f[i - 1]); //持久化

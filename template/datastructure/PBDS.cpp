#include <bits/extc++.h>
using namespace __gnu_pbds;

/*
    hash表
*/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;

cc_hash_table<string, int> mp1; //拉链法
gp_hash_table<string, int> mp2; //查探法(快一些)

/*
    堆
*/
#include <ext/pb_ds/priority_queue.hpp>
using namespace __gnu_pbds;
__gnu_pbds::priority_queue<int> q;                                  //因为放置和std重复，故需要带上命名空间
__gnu_pbds::priority_queue<int, greater<int>, pairing_heap_tag> pq; //最快
__gnu_pbds::priority_queue<int, greater<int>, binary_heap_tag> pq;
__gnu_pbds::priority_queue<int, greater<int>, binomial_heap_tag> pq;
__gnu_pbds::priority_queue<int, greater<int>, rc_binomial_heap_tag> pq;
__gnu_pbds::priority_queue<int, greater<int>, thin_heap_tag> pq;
__gnu_pbds::priority_queue<int, greater<int>> pq;

//堆的常用操作
push();                                             //会返回一个迭代器
top();                                              //同 stl
size();                                             //同 stl
empty();                                            //同 stl
clear();                                            //同 stl
pop();                                              //同 stl
join(priority_queue &other);                        //合并两个堆,other会被清空
split(Pred prd, priority_queue &other);             //分离出两个堆
modify(point_iterator it, const key);               //修改一个节点的值
__gnu_pbds::priority_queue<int>::point_iterator it; //迭代器

/*
    红黑树,不可插入重复键值（自动去重）
*/
tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> t;

#define pii pair<int, int>
#define mp(x, y) make_pair(x, y)
tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> tr;
pii;                               //存储的类型
null_type;                         //无映射(低版本g++为null_mapped_type)
less<pii>;                         //从小到大排序
rb_tree_tag;                       //红黑树
tree_order_statistics_node_update; //更新方式
tr.insert(mp(x, y));               //插入;
tr.erase(mp(x, y));                //删除;
tr.order_of_key(pii(x, y));        //求排名
tr.find_by_order(x);               //找k小值，返回迭代器
tr.join(b);                        //将b并入tr，前提是两棵树类型一样且没有重复元素
tr.split(v, b);                    //分裂，key小于等于v的元素属于tr，其余的属于b
tr.lower_bound(x);                 //返回第一个大于等于x的元素的迭代器
tr.upper_bound(x);                 //返回第一个大于x的元素的迭代器
//以上所有操作的时间复杂度均为O(logn)

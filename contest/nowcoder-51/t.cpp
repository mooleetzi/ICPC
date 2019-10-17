#include <bits/extc++.h>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
int main(int argc, char const *argv[])
{
    __gnu_pbds::tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> t;
    t.insert(1);
    t.insert(1);
    t.insert(2);
    std::cout << t.size();
    return 0;
}

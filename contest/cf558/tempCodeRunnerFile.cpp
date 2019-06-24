inline int judge(int x)
// {
//     multiset<int> s1;
//     set<int> s2;
//     s1.clear(), s2.clear();
//     for (int i = 1; i <= 10; i++)
//     {
//         int t = pre[x][i];
//         if (t)
//             s1.insert(t), s2.insert(t);
//     }
//     if (s2.size() > 2)
//         return false;
//     if (s2.size() == 1)
//     {
//         int k = s1.count(*s2.begin());
//         return k == 1 || *s2.begin() == 1;
//     }
//     int t1 = 0, t2 = 0;
//     int x1 = *(s2.begin()); //最小出现次数
//     s2.erase(s2.begin());
//     int x2 = *(s2.begin()); //最大出现次数
//     s2.erase(s2.begin());
//     t1 = s1.count(x1), t2 = s1.count(x2);
//     if (t1 == 1 && x1 == 1)
//         return true;
//     if (t2 == 1 && abs(x1 - x2) == 1)
//         return true;
//     return false;
// }
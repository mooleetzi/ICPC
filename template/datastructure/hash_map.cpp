const int SZ = 1e5;
struct hash_map
{ // 哈希表模板
  struct data
  {
    long long u;
    int v, nex;
  };               // 前向星结构
  data e[SZ << 1]; // SZ 是 const int 表示大小
  int h[SZ], cnt;
  int hash(long long u) { return u % SZ; }
  int &operator[](long long u)
  {
    int hu = hash(u); // 获取头指针
    for (int i = h[hu]; i; i = e[i].nex)
      if (e[i].u == u)
        return e[i].v;
    return e[++cnt] = (data){u, -1, h[hu]}, h[hu] = cnt, e[cnt].v;
  }
  hash_map()
  {
    cnt = 0;
    memset(h, 0, sizeof(h));
  }
};
//防止unordered_set,unordered_map被卡
//unordered_set<int,int,custom_hash> mp;
struct custom_hash
{
  static uint64_t splitmix64(uint64_t x)
  {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const
  {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
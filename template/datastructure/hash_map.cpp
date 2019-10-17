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
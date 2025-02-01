#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

struct UnionFind
{
  std::vector<long long> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
  vector<long long> _size;
  UnionFind(long long N) : par(N), _size(N)
  { // 最初は全てが根であるとして初期化
    for (long long i = 0; i < N; i++)
    {
      par[i] = i;
      _size[i] = 1;
    }
  }

  long long root(long long x)
  { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
    if (par[x] == x)
      return x;
    return par[x] = root(par[x]);
  }

  void unite(long long x, long long y)
  {                         // xとyの木を併合
    long long rx = root(x); // xの根をrx
    long long ry = root(y); // yの根をry
    if (rx < ry)
    {
      swap(rx, ry); // 添字が小さい方を根にする
    }
    if (rx == ry)
      return;     // xとyの根が同じ(=同じ木にある)時はそのまま
    par[rx] = ry; // xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    _size[ry] += _size[rx];
  }

  bool same(long long x, long long y)
  { // 2つのデータx, yが属する木が同じならtrueを返す
    long long rx = root(x);
    long long ry = root(y);
    return rx == ry;
  }

  long long size(long long x)
  {
    return _size[root(x)];
  }
};

int main()
{
  int n, k;
  string s;
  cin >> n >> k >> s;
  UnionFind uf(n);
  vector<bool> used(n, false);
  priority_queue<tuple<int, int, int>> q;
  int x = 0;
  int ans = 0;
  REP(i, n)
  {
    if (s[i] == 'X')
      x++;
  }
  if (x == n)
  {
    ans = max(0, k - 1);
  }
  else
  {
    if (k > x)
    {
      k = n - k;
      REP(i, n)
      {
        if (s[i] == 'X')
          s[i] = 'Y';
        else
          s[i] = 'X';
      }
    }

    REP(i, n - 1)
    {
      if (s[i] == 'X' && s[i + 1] == 'X')
      {
        uf.unite(i, i + 1);
      }
    }
    REP(i, n)
    {
      if (!used[uf.root(i)] && s[i] == 'X')
      {
        if (i == 0 || i + uf.size(i) == n)
        {
          q.push({0, -uf.size(i), i});
        }
        else
        {
          q.push({1, -uf.size(i), i});
        }
        used[uf.root(i)] = true;
      }
    }
    used.assign(n, false);
    while (!q.empty() && k > 0)
    {
      auto [tmp, m, l] = q.top();
      q.pop();
      m *= -1;
      int r = l;
      while (k > 0 && r < l + m)
      {
        s[r] = 'Y';
        used[r] = true;
        r++;
        k--;
      }
    }

    REP(i, n - 1)
    {
      if (s[i] == 'Y' && s[i + 1] == 'Y')
      {
        ans++;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

const int INF = 1e9;
template <typename T>
class Sum
{
public:
  // 単位元
  T unit;

  Sum(void)
  {
    // 単位元
    unit = 0;
  }

  // 演算関数
  T calc(T a, T b)
  {
    return a + b;
  }
};
template <typename T, class MONOID>
class SegmentTree
{
public:
  // セグメント木の葉の要素数
  int n;

  // セグメント木
  vector<T> tree;

  // モノイド
  MONOID mono;

  SegmentTree(vector<T> &v) : n(1 << (int)ceil(log2(v.size()))), tree(vector<T>(n << 1))
  {
    for (int i = 0; i < v.size(); ++i)
    {
      update(i, v[i]);
    }
    for (int i = v.size(); i < n; ++i)
    {
      update(i, mono.unit);
    }
  }

  // k番目の値(0-indexed)をxに変更
  void update(int k, T x)
  {
    k += n;
    tree[k] = x;
    for (k = k >> 1; k > 0; k >>= 1)
    {
      tree[k] = mono.calc(tree[k << 1 | 0], tree[k << 1 | 1]);
    }
  }

  // [s, t)の最小値(0-indexed)を求める．
  T query(int s, int t)
  {
    T res = mono.unit;
    s += n;
    t += n;
    while (s < t)
    {
      if (s & 1)
      {
        res = mono.calc(res, tree[s++]);
      }
      if (t & 1)
      {
        res = mono.calc(res, tree[--t]);
      }
      s >>= 1;
      t >>= 1;
    }
    return res;
  }

  T operator[](int k)
  {
    // st[i]で添字iの要素の値を返す
    if (k - n >= 0 || k < 0)
    {
      return -INF;
    }
    return tree[tree.size() - n + k];
  }
};

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1, 0);
  REP(i, n)
  {
    cin >> a[i + 1];
  }
  // vector<vector<int>> b;
  // b.resize(n);
  // REP(i, n){
  //   b[i] = a;
  // }
  REP(i, n)
  {
    SegmentTree<int, Sum<int>> st(a);
    FOR(j, i + 1, n + 1)
    {
      if (a[j] != 0)
      {
        st.
      }
    }
  }

  int q;
  cin >> q;
  int l, r;
  REP(i, q)
  {
    cin >> l >> r;
    if (k == 1)
    {
      puts("Yes");
    }
    else
    {
      if (a[l] == st.query(l, r))
      {
        puts("Yes");
      }
      else
      {
        puts("No");
      }
    }
  }
  return 0;
}

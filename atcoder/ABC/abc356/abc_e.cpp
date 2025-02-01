#include <bits/stdc++.h>
#include <atcoder/modint>

using namespace std;
using namespace atcoder;

using mint = modint1000000007;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)
#define RFOR(i, a, b) for (ll i = b - 1; i >= a; i--)
#define RREP(i, n) for (ll i = n - 1; i >= 0; i--)
#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vvll = vector<vector<ll>>;
using vll = vector<ll>;
constexpr long long INF = (1LL << 60);
void debug_out()
{
  cerr << endl;
}

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
  cerr << H << " ";
  debug_out(T...);
}

#define debug(...) debug_out(__VA_ARGS__)
constexpr int MOD = 1000000000 + 7;


// 非再帰SegmentTree (0-based indexだった気がする)
template <typename T>
struct SegmentTree
{
    std::vector<T> node;
    int n;
    T Identity;
    std::function<T(T, T)> Func;

    SegmentTree(int _n, const T &identity, const std::function<T(T, T)> &func)
    {
        n = 1;
        while (n < _n)
            n <<= 1;
        Identity = identity;
        node.assign(2 * n, identity);
        Func = func;
    }

    void build(std::vector<T> array)
    {
        for (size_t i = 0; i < array.size(); i++)
        {
            node[i + n] = array[i];
        }
        for (size_t i = n - 1; i > 0; i--)
        {
            size_t l = i << 1 | 0;
            size_t r = i << 1 | 1;
            node[i] = Func(node[l], node[r]);
        }
    }

    void update(int i, T v)
    {
        int j = n + i;
        node[j] = v;
        while (j > 1)
        {
            j >>= 1;
            size_t l = j << 1 | 0;
            size_t r = j << 1 | 1;
            node[j] = Func(node[l], node[r]);
        }
    }

    T fold(int l, int r)
    {
        l += n;
        r += n;
        T vl = Identity, vr = Identity;
        while (l < r)
        {
            if ((l & 1) == 1)
            {
                vl = Func(vl, node[l]);
                l++;
            }
            if ((r & 1) == 1)
            {
                r--;
                vr = Func(node[r], vr);
            }
            l >>= 1;
            r >>= 1;
        }
        return Func(vl, vr);
    }
};


int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  int m = 0;
  REP(i, n){
    cin >> a[i];
    m = max(a[i], m);
  }
  sort(all(a));
  m+=10;
  SegmentTree<int> seg(m, 0, [](int a, int b) { return a + b; });
  seg.build(vector<int>(m, 0));
  REP(i, n)
  {
    int x = seg.fold(a[i], a[i]+1);
    seg.update(a[i], x + 1);
  }
  ll ans = 0;
  REP(i, n){
    int ai = a[i];
    int m = 1;
    debug("ai=", ai);
    // 同じ数があったら、その分組み合わせが増えるのでたす
    ans += seg.fold(ai, ai + 1) * (seg.fold(ai, ai + 1) - 1) / 2;
    debug(seg.fold(ai, ai + 1) * (seg.fold(ai, ai + 1) - 1) / 2);
    ans += seg.fold(ai * m+1, ai * (m + 1)) * m * seg.fold(ai, ai + 1);
    debug(seg.fold(ai * m+1, ai * (m + 1)) * m) * seg.fold(ai, ai + 1));
    m++;
    while (ai * m <= a[n-1]){
      // 二分探索で ai * m より大きい値を探す
      auto iter = lower_bound(all(a), ai * m);
      int idx = distance(a.begin(), iter);
      if (a[idx] >= ai * (m+1)){
        m = a[idx] / ai;
      }
      ans += seg.fold(ai * m, ai * (m + 1)) * m; // * seg.fold(ai, ai + 1);
      debug(seg.fold(ai * m, ai * (m + 1)) * m);// * seg.fold(ai, ai + 1));
      m++;
    }
    debug("ans=", ans);
  }
  cout << ans << endl;

}

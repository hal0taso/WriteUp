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

// 遅延伝搬SegmentTree
template <typename TN, typename TL>
class LazySegmentTree
{
  using FN = std::function<TN(TN, TN)>;
  using FL = std::function<TL(TL, TL)>;
  using FNL = std::function<TN(TN, TL)>;

private:
  int n;
  int size;
  int height;

public:
  TN IdentityNode; // 値データの単位元
  TL IdentityLazy; // 遅延データの単位元

  FN CombineNodeFunc; // 値データの作用. F: Node x Node -> Node. RMQならmin, RSQなら+
  FL CombineLazyFunc; // 遅延データの伝搬作用. F: Lazy x Lazy -> Lazy. 区間加算なら+, 区間更新なら=(代入)
  FNL ReflectFunc;    // 遅延データを値データにどう反映させるか. F: Node x Lazy -> Node. 区間加算なら+, 区間更新なら=(代入)
  std::vector<TN> node;
  std::vector<TL> lazy;

  LazySegmentTree(int _n, const TN &identityNode, const TL &identityLazy,
                  const FN &combineNodeFunc, const FL &combineLazyFunc,
                  const FNL &reflectFunc)
  {
    n = _n;
    size = 1;
    height = 0;
    while (size < n)
      size <<= 1, height++;
    IdentityNode = identityNode;
    IdentityLazy = identityLazy;
    CombineNodeFunc = combineNodeFunc;
    CombineLazyFunc = combineLazyFunc;
    ReflectFunc = reflectFunc;
    node = std::vector<TN>(2 * size, IdentityNode);
    lazy = std::vector<TL>(2 * size, IdentityLazy);
  }

private:
  TN reflect_lazy(int index)
  {
    return ReflectFunc(node[index], lazy[index]);
  }

  void propergate_from_top(int index)
  {
    index += size;
    for (int h = height; h > 0; h--)
    {
      int i = index >> h;
      if (lazy[i] != IdentityLazy)
      {
        lazy[i << 1 | 0] = CombineLazyFunc(lazy[i << 1 | 0], lazy[i]);
        lazy[i << 1 | 1] = CombineLazyFunc(lazy[i << 1 | 1], lazy[i]);
        node[i] = reflect_lazy(i);
        lazy[i] = IdentityLazy;
      }
    }
  }

  void update_from_bottom(int index)
  {
    index = (index + size) >> 1;
    while (index > 0)
    {
      node[index] = CombineNodeFunc(reflect_lazy(index << 1 | 0), reflect_lazy(index << 1 | 1));
      index >>= 1;
    }
  }

public:
  void build(std::vector<TN> array)
  {
    for (size_t i = 0; i < array.size(); i++)
    {
      node[i + size] = array[i];
    }
    for (size_t i = size - 1; i > 0; i--)
    {
      size_t l = i << 1 | 0;
      size_t r = i << 1 | 1;
      node[i] = CombineNodeFunc(node[l], node[r]);
    }
  }

  void update(int l, int r, TL value)
  {
    propergate_from_top(l);
    propergate_from_top(r - 1);
    int l_lazy = l + size;
    int r_lazy = r + size;
    while (l_lazy < r_lazy)
    {
      if (l_lazy & 1)
      {
        lazy[l_lazy] = CombineLazyFunc(lazy[l_lazy], value);
        l_lazy++;
      }
      if (r_lazy & 1)
      {
        r_lazy--;
        lazy[r_lazy] = CombineLazyFunc(lazy[r_lazy], value);
      }
      l_lazy >>= 1;
      r_lazy >>= 1;
    }
    update_from_bottom(l);
    update_from_bottom(r - 1);
  }

  void update(int index, TL value)
  {
    update(index, index + 1, value);
  }

  TN fold(int l, int r)
  {
    propergate_from_top(l);
    propergate_from_top(r - 1);
    l += size;
    r += size;
    TN value_l = IdentityNode;
    TN value_r = IdentityNode;
    while (l < r)
    {
      if (l & 1)
      {
        value_l = CombineNodeFunc(value_l, reflect_lazy(l));
        l++;
      }
      if (r & 1)
      {
        r--;
        value_r = CombineNodeFunc(reflect_lazy(r), value_r);
      }
      l >>= 1;
      r >>= 1;
    }
    return CombineNodeFunc(value_l, value_r);
  }

  int get_size()
  {
    return size;
  }

  int get_height()
  {
    return height;
  }
};

struct N
{
  int value;
  int size;

  bool operator==(const N &rhs)
  {
    return value == rhs.value && size == rhs.size;
  }

  N operator+(const N &rhs)
  {
    return {value + rhs.value, size + rhs.size};
  }
};

using L = int;
const L ID = int(-1);

int main()
{
  int n, q;
  cin >> n >> q;
  vector<tuple<ll, ll, ll>> a(q);
  REP(i, q)
  {
    ll l, r, c;
    cin >> l >> r >> c;
    l--, r--;
    a[i] = make_tuple(c, l, r);
  }
  sort(all(a));
  N e(0, 0);
  L id = ID;

  function<N(N, N)> opN = [](N left, N right)
  { return left + right; };
  function<N(N, L)> reflect = [](N node, L lazy)
  {
    if (lazy != ID)
      node.value = node.size * lazy;
    return node;
  };

  function<L(L, L)> opL = [](L ll, L rl)
  { if (ll == ID) return rl; return ll; };
  LazySegmentTree<N, L> st(n + 1, e, id, opN, opL, reflect);
  // debug("! size", st.get_size());
  // debug("! height", st.get_height());

  st.build(vector<N>(n + 1, N(1, 1)));
  ll ans = 0;
  for (auto [c, l, r] : a)
  {
    ans += (st.fold(l, r).value + 1) * c;
    // debug("-- before --");
    // REP(i, 2 * st.get_size())
    // {
    //   debug("D", i, st.node[i].value, st.node[i].size, st.lazy[i]);
    //   REP(j, st.get_height() + 1)
    //   if (i == (1 << j) - 1)
    //   {
    //     debug("-- height:", j, "--");
    //     break;
    //   }
    // }

    // debug("!", l, r, c, st.fold(l, r + 1).value, ans);
    st.update(l, r, L(0));
    // debug("-- after --");
    // REP(i, 2 * st.get_size())
    // {
    //   debug("D", i, st.node[i].value, st.node[i].size, st.lazy[i]);
    //   REP(j, st.get_height() + 1)
    //   if (i == (1 << j) - 1)
    //   {
    //     debug("-- height:", j, "--");
    //     break;
    //   }
    // }
  }
  if (st.fold(0, n).value != 1)
  {
    cout << -1 << endl;
    return 0;
  }
  cout << ans << endl;
}

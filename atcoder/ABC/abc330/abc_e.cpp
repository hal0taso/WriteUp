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
constexpr int INF = (1 << 30);
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

auto isin(set<pair<int, int>> &st, int x)
{
  auto itr = st.lower_bound(make_pair(x + 1, x + 1));
  itr--;
  // debug("isin", x, itr->first, itr->second);
  if ((itr->first <= x) && (x <= itr->second))
    return itr;
  return st.end();
}

void add(set<pair<int, int>> &st, int x)
{
  if (isin(st, x) != st.end())
  {
    // debug("skip");
    return;
  }
  int l1 = -INF, r1 = -INF, l2 = INF, r2 = INF;
  if (isin(st, x - 1) != st.end())
  {
    auto itr = isin(st, x - 1);
    l1 = itr->first, r1 = itr->second;
  }
  if (isin(st, x + 1) != st.end())
  {
    auto itr = isin(st, x + 1);
    l2 = itr->first, r2 = itr->second;
  }
  // debug("add", l1, r1, l2, r2);
  if (r1 > -INF && l2 < INF)
  {
    st.erase({l1, r1});
    st.erase({l2, r2});
    st.insert({l1, r2});
  }
  else if (r1 > -INF)
  {
    st.erase({l1, r1});
    st.insert({l1, x});
  }
  else if (l2 < INF)
  {
    st.erase({l2, r2});
    st.insert({x, r2});
  }
  else
  {
    st.insert({x, x});
  }
}

void remove(set<pair<int, int>> &st, int x)
{
  if (isin(st, x) == st.end())
    return;
  auto itr = isin(st, x);
  int l = itr->first, r = itr->second;
  st.erase(*itr);
  if (l < x)
    st.insert({l, x - 1});
  if (r > x)
    st.insert({x + 1, r});
}

int mex(set<pair<int, int>> &st, int x)
{
  if (isin(st, x) == st.end())
    return x;
  auto itr = isin(st, x);
  int r = itr->second;
  return ++r;
}

int main()
{
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto &e : a)
    cin >> e;
  set<pair<int, int>> st;
  st.insert({-INF, -INF});
  st.insert({INF, INF});
  map<int, int> mp;
  REP(i, n)
  {
    mp[a[i]]++;
  }
  int l = -INF, r = -INF;
  for (auto itr = mp.begin(); itr != mp.end(); ++itr)
  {
    if (itr->first == r + 1)
      r++;
    else
    {
      st.insert({l, r});
      l = itr->first;
      r = itr->first;
    }
  }
  st.insert({l, r});

  // debug("debug");
  // for (auto itr = st.begin(); itr != st.end(); ++itr)
  // {
  //   debug(itr->first, itr->second);
  // }

  while (q--)
  {
    int t, x;
    cin >> t >> x;
    t--;
    mp[a[t]]--;
    if (mp[a[t]] == 0)
    {
      // debug("remove", a[t]);
      remove(st, a[t]);
    }
    a[t] = x;
    add(st, x);
    mp[x]++;
    cout << mex(st, 0) << '\n';
    // debug("add", x);
    // for (auto itr = st.begin(); itr != st.end(); ++itr)
    // {
    //   debug(itr->first, itr->second);
    // }
  }
}

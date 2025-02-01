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

int main()
{
  int n, q;
  cin >> n >> q;
  vector<set<int>> s(n);
  vector<int> idx(n);
  REP(i, n)
  idx[i] = i;

  REP(i, n)
  {
    int c;
    cin >> c;
    s[i].insert(c);
  }
  REP(i, q)
  {
    // debug("debug");
    // for (auto j : idx)
    //   debug(j);
    int a, b;
    cin >> a >> b;
    a--, b--;
    if (s[idx[a]].size() > s[idx[b]].size())
    {
      swap(idx[a], idx[b]);
    }
    for (auto x : s[idx[a]])
    {
      s[idx[b]].insert(x);
    }
    s[idx[a]].clear();
    cout << s[idx[b]].size() << endl;
  }
}

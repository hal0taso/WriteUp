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

constexpr int MOD = 1000000000 + 7;

using Graph = vector<set<int>>;

int main()
{
  int n;
  int q;
  cin >> n >> q;
  Graph G(n);
  vector<int> deg(n, 0);
  int ans = n;
  REP(i, q)
  {
    int t, u, v;
    cin >> t;
    if (t == 1)
    {
      cin >> u >> v;
      u--, v--;
      G[u].insert(v);
      G[v].insert(u);
      if (deg[u] == 0)
        ans--;
      if (deg[v] == 0)
        ans--;
      deg[u]++;
      deg[v]++;
    }
    if (t == 2)
    {
      cin >> v;
      v--;
      if (deg[v] > 0)
      {
        for (auto x : G[v])
        {
          G[x].erase(v);
          deg[x]--;
          if (deg[x] == 0)
            ans++;
        }
        G[v].clear();
        deg[v] = 0;
        ans++;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
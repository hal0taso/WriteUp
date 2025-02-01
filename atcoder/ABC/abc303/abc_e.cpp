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
  cin >> n;
  Graph G(n);
  REP(i, n - 1)
  {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G[u].insert(v);
    G[v].insert(u);
  }
  int v;
  REP(i, n)
  {
    if (G[i].size() == 1)
    {
      v = i;
      break;
    }
  }
  vector<int> ans;
  queue<int> que;
  que.push(v);
  while (!que.empty())
  {
    v = que.front();
    // cerr << v << '\n';
    que.pop();
    int c = *G[v].begin();
    int l = G[c].size();
    ans.push_back(l);

    // cerr << c << '\n';
    for (int u : G[c])
    {
      G[u].erase(c);
      for (int w : G[u])
      {
        // cerr << w << '\n';
        que.push(w);
        G[w].erase(u);
      }
      for (int w : G[u])
      {
        G[u].erase(w);
      }
      // G[u].erase(w);
      // G[u].clear();
    }
    G[c].clear();
  }
  sort(all(ans));
  REP(i, (int)ans.size())
  {
    cout << ans[i];
    if (i < (int)ans.size() - 1)
      cout << ' ';
    else
      cout << '\n';
  }

  return 0;
}
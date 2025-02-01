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
using Graph = std::vector<std::vector<int>>;
vector<bool> seen;

bool dfs(int v, int p, int n)
{
  seen[v] = true;
  bool ret = false;
  if (v == n)
  {
    string s;
    cin >> s;
    return true;
  }
  else
  {
    int k;
    cin >> k;
    if (k == -1)
      return true;
    vector<int> nb(k);
    REP(i, k)
    {
      cin >> nb[i];
    }
    // if (!seen[v])
    // {
    //   REP(i, k)
    //   G[v].push_back(nb[i]);
    // }
    for (auto next_v : nb)
    {
      if (!seen[next_v])
      {
        cout << next_v << '\n'
             << flush;
        ret = dfs(next_v, v, n);
      }
      if (ret)
        return ret;
    }
    cout << p << '\n'
         << flush;
    cin >> k;
    int x;
    REP(i, k)
    {
      cin >> x;
    }
    return ret;
  }
}

int main()
{
  int n, m;
  cin >> n >> m;
  // Graph G(n);
  seen.assign(n + 1, false);
  int now = 1;
  dfs(now, -1, n);

  return 0;
}
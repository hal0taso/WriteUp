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

constexpr int MOD = 1000000000 + 7;

constexpr long long INF = (1LL << 60);

using Graph = std::vector<std::vector<int>>;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> p(n);
  Graph G(n);
  FOR(i, 1, n)
  {
    cin >> p[i];
    p[i]--;
    G[p[i]].push_back(i);
  }
  vector<int> x(m), y(m);
  vector<int> ans(n, 0);
  REP(i, m)
  {
    cin >> x[i] >> y[i];
    x[i]--;
    y[i]++;
    ans[x[i]] = max(ans[x[i]], y[i]);
  }
  priority_queue<pair<int, int>> que;
  REP(i, n)
  {
    if (ans[i] > 0)
    {
      que.push({ans[i], i});
    }
  }
  vector<bool> seen(n, false);
  while (!que.empty())
  {
    auto [val, v] = que.top();
    que.pop();
    if (seen[v])
      continue;
    seen[v] = true;
    if (val == 1)
      continue;
    val--;
    for (int next_v : G[v])
    {
      if (seen[next_v])
        continue;
      ans[next_v] = val;
      que.push({val, next_v});
    }
  }

  int cnt = 0;
  REP(i, n)
  {
    if (ans[i] > 0)
      cnt++;
  }
  cout << cnt << '\n';

  return 0;
}
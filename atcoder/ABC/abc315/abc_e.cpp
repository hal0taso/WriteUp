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

using Graph = vector<vector<int>>;

void dfs(const Graph &G, int v, vector<bool> &used, vector<int> &ans)
{
  used[v] = true;
  for (auto next_v : G[v])
  {
    if (!used[next_v])
    {
      dfs(G, next_v, used, ans);
    }
  }
  ans.push_back(v); // 帰りがけにpush_back
}
vector<int> topo_sort(const Graph &G)
{ // bfs
  vector<int> ans;
  int n = (int)G.size();
  vector<bool> used(n, false);
  dfs(G, 0, used, ans);
  // for (int v = 0; v < n; v++)
  // { // 未探索の頂点ごとにDFS
  //   if (!used[v])
  //     dfs(G, v, used, ans);
  // }
  // reverse(ans.begin(), ans.end()); // 逆向きなのでひっくり返す
  return ans;
}

int main()
{
  int n;
  cin >> n;
  Graph G(n);
  REP(i, n)
  {
    int c;
    cin >> c;
    REP(j, c)
    {
      int p;
      cin >> p;
      p--;
      G[i].push_back(p);
    }
  }
  vector<int> ans = topo_sort(G);

  REP(i, ans.size() - 1)
  {
    cout << ans[i] + 1;
    if (i < ans.size() - 2)
      cout << ' ';
    else
      cout << '\n';
  }
  return 0;
}
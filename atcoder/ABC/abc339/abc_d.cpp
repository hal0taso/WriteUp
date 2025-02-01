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

vector<pair<int, int>> diff = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

vector<int> bfs(vector<vector<int>> &g, int start)
{
  int n = g.size();
  vector<int> dist(n, -1);
  queue<int> q;
  q.push(start);
  dist[start] = 0;
  while (!q.empty())
  {
    int v = q.front();
    q.pop();
    for (auto nv : g[v])
    {
      if (dist[nv] != -1)
      {
        continue;
      }
      dist[nv] = dist[v] + 1;
      q.push(nv);
    }
  }
  return dist;
}

bool is_valid(vector<string> &s, int i, int j, int n)
{
  return i >= 0 && i < n && j >= 0 && j < n && s[i][j] != '#';
};

int main()
{
  int n;
  cin >> n;
  vector<string> s(n);
  REP(i, n)
  {
    cin >> s[i];
  }

  // まず到達可能性の判定をする
  vector<vector<int>> g(n * n * n * n);

  vector<pair<int, int>> player;
  REP(i, n)
  {
    REP(j, n)
    {
      if (s[i][j] == 'P')
      {
        player.push_back({i, j});
      }
    }
  }

  REP(i, n)
  REP(j, n)
  REP(k, n)
  REP(l, n)
  {
    if (s[i][j] == '#')
    {
      continue;
    }
    if (s[k][l] == '#')
    {
      continue;
    }
    int ni, nj, nk, nl;
    REP(d, 4)
    {
      ni = i + diff[d].first;
      nj = j + diff[d].second;
      nk = k + diff[d].first;
      nl = l + diff[d].second;
      if (!is_valid(s, ni, nj, n))
      {
        ni = i;
        nj = j;
      }
      if (!is_valid(s, nk, nl, n))
      {
        nk = k;
        nl = l;
      }
      g[i * n * n * n + j * n * n + k * n + l].push_back(ni * n * n * n + nj * n * n + nk * n + nl);
    }
  }
  int start = player[0].first * n * n * n + player[0].second * n * n + player[1].first * n + player[1].second;
  auto dist = bfs(g, start);
  int ans = INF;
  REP(i, n)
  {
    REP(j, n)
    {
      if (s[i][j] == '.')
      {
        if (dist[i * n * n * n + j * n * n + i * n + j] == -1)
        {
          continue;
        }
        ans = min(dist[i * n * n * n + j * n * n + i * n + j], ans);
      }
    }
  }
  if (ans == INF)
    ans = -1;
  cout << ans << endl;
}

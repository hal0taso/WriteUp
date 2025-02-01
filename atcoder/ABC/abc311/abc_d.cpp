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

void dfs(const vector<string> &S, int x, int y, int pdx, int pdy, vector<vector<bool>> &seen, vector<vector<bool>> &ans)
{
  seen[x][y] = true;
  ans[x][y] = true;
  int nx, ny;
  for (int dx : {-1, 1})
  {
    nx = x, ny = y;
    if (dx == pdx)
      continue;
    while (S[nx][ny] == '.')
    {
      ans[nx][ny] = true;
      nx += dx;
    }
    nx -= dx;
    if (!seen[nx][ny])
      dfs(S, nx, ny, -dx, 0, seen, ans);
  }
  for (int dy : {-1, 1})
  {
    nx = x, ny = y;

    if (dy == pdy)
      continue;
    while (S[nx][ny] == '.')
    {
      ans[nx][ny] = true;
      ny += dy;
    }
    ny -= dy;
    if (!seen[nx][ny])
      dfs(S, nx, ny, 0, -dy, seen, ans);
  }
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<string> S(n);
  vector<vector<bool>> seen(n, vector<bool>(m, false));
  vector<vector<bool>> ans(n, vector<bool>(m, false));
  REP(i, n)
  cin >> S[i];
  dfs(S, 1, 1, 0, 0, seen, ans);
  int cnt = 0;
  REP(i, n)
  {
    REP(j, m)
    {
      if (ans[i][j])
        cnt++;
    }
  }
  cout << cnt << '\n';
  return 0;
}
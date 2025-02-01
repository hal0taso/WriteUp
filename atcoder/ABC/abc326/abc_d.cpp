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

bool check(int n, vector<string> &s, string &c, string &r)
{
  vector n_cols(n, vector<int>(3, 0)), n_rows(n, vector<int>(3, 0));
  string s_cols(n, '.'), s_rows(n, '.');

  REP(i, n)
  {
    REP(j, n)
    {
      if (s[i][j] != '.')
      {
        if (s_rows[i] == '.')
          s_rows[i] = s[i][j];
        n_rows[i][s[i][j] - 'A']++;
      }
    }
  }
  REP(j, n)
  {
    REP(i, n)
    {
      if (s[i][j] != '.')
      {
        if (s_cols[j] == '.')
          s_cols[j] = s[i][j];
        n_cols[j][s[i][j] - 'A']++;
      }
    }
  }
  bool res = true;
  REP(i, n)
  {
    if (s_rows[i] != r[i])
      res = false;
    if (s_cols[i] != c[i])
      res = false;
    REP(j, 3)
    {
      if (n_rows[i][j] != 1)
        res = false;
      if (n_cols[i][j] != 1)
        res = false;
    }
  }
  return res;
}

bool dfs(int n, int d, string &r, string &c, vector<string> &ans)
{
  if (d == n)
    return check(n, ans, c, r);
  vector<char> v;
  for (char i = 'A'; i <= 'C'; i++)
    if (i != r[d])
      v.push_back(i);

  FOR(i, 0, n)
  {
    FOR(j, i + 1, n)
    {
      FOR(k, i + 1, n)
      {
        if (k == j)
          continue;
        string s(n, '.');
        s[i] = r[d];
        s[j] = v[0];
        s[k] = v[1];
        ans[d] = s;
        bool ret = dfs(n, d + 1, r, c, ans);
        if (ret)
          return ret;
      }
    }
  }
  return false;
}

int main()
{
  int n;
  string r, c;
  cin >> n >> r >> c;
  vector<string> ans(n, string(n, '.'));
  bool ret = dfs(n, 0, r, c, ans);
  if (ret)
    puts("Yes");
  else
    puts("No");

  if (ret)
  {
    REP(i, n)
    {
      puts(ans[i].c_str());
    }
  }
  return 0;
}

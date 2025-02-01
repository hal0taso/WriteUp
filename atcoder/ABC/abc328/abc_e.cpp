#include <bits/stdc++.h>
#include <atcoder/modint>

using namespace std;
using namespace atcoder;

using mint = modint1000000007;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
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

void solve(string &s, string &t, int n, int m, int i)
{
  // debug(i);
  if (i + m > n)
    return;
  bool flg = true;
  REP(j, m)
  {
    if (j > 0 && s[i + j] == t[0])
      solve(s, t, n, m, i + j);
    if (s[i + j] == '#' || s[i + j] == t[j])
      continue;
    else
    {
      flg = false;
      break;
    }
  }
  if (flg)
  {
    REP(j, m)
    {
      s[i + j] = '#';
    }
  }
}

int main()
{
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  REP(i, n)
  {
    solve(s, t, n, m, i);
  }
  string ans = "Yes";
  // debug(s);
  REP(i, n)
  {
    if (s[i] != '#')
    {
      ans = "No";
      break;
    }
  }
  cout << ans << endl;
}

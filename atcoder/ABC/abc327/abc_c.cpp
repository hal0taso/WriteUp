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
  ll n = 9;
  vector a(n, vector<int>(n));
  for (auto &i : a)
    for (auto &j : i)
      cin >> j;

  vector<set<int>> col(n), row(n), square(n);
  REP(i, n)
  REP(j, n)
  {
    col[i].insert(a[i][j]);
    row[j].insert(a[i][j]);
    square[(i / 3) * 3 + j / 3].insert(a[i][j]);
  }
  string ans = "Yes";
  REP(i, n)
  {
    if (col[i].size() != n)
      ans = "No";
    if (row[i].size() != n)
      ans = "No";
    if (square[i].size() != n)
      ans = "No";
  }
  puts(ans.c_str());
}

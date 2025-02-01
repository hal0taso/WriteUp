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
  vector P(3, vector<string>(4));
  REP(k, 3)
  REP(i, 4)
  cin >> P[k][i];
  vector<int> sx(3);
  vector<int> tx(3);
  vector<int> sy(3);
  vector<int> ty(3);
  REP(k, 3)
  {
    REP(i, 4)
    REP(j, 4)
    if (P[k][i][j] == '#')
      tx[k] = i, ty[k] = j;
    RREP(i, 4)
    RREP(j, 4)
    if (P[k][i][j] == '#')
      sx[k] = i, sy[k] = j;
  }

  return 0;
}
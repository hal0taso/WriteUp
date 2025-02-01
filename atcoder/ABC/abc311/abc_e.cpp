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

int main()
{
  int h, w, n;
  cin >> h >> w >> n;
  vector<int> a(n);
  vector<int> b(n);
  vector<vector<int>> s(h, vector<int>(w, 0));
  REP(i, n)
  {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    s[a[i]][b[i]]++;
  }

  FOR(i, 1, h)
  {
    REP(j, w)
    {
      s[i][j] += s[i - 1][j];
    }
  }
  FOR(j, 1, w)
  {
    REP(i, h)
    {
      s[i][j] += s[i][j - 1];
    }
  }
  // REP(i, h)
  // {
  //   REP(j, w)
  //   cerr << s[i][j];
  //   cerr << '\n';
  // }
  ll ans = 0;
  REP(i, h)
  {
    REP(j, w)
    {
      int lb = 1;
      int ub = min(h - i, w - j) + 1;
      while (lb + 1 < ub)
      {
        int m = (lb + ub) / 2;
        if (i + m - 1 < h && j + m - 1 < w && s[i + m - 1][j + m - 1] - s[i][j] == 0)
          lb = m;
        else
          ub = m;
      }
      ans += lb;
      // cerr << i << "," << j << ":" << lb << '\n';
      if (s[i][j] != 0)
        ans--;
    }
  }
  cout << ans << '\n';
  return 0;
}
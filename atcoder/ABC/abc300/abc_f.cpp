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
  ll n, m, k;
  cin >> n >> m >> k;
  string s;
  cin >> s;
  // cum[i]: s_{i+1}番目までの'x'の個数
  vector<ll> cum(n + 1, 0);
  // coord[i]: 'x'の個数がi個以下の最大の座標(1-index)
  vector<ll> coord(n + 1, 0);

  REP(i, n)
  {
    cum[i + 1] = cum[i];
    if (s[i] == 'x')
      cum[i + 1]++;
  }
  REP(i, n + 1)
  {
    coord[cum[i]] = i;
  }
  ll ans = 0;
  FOR(i, 1, n + 1)
  {
    ll rem = k;
    ll tmp = 0;
    ll mm = m;
    if (rem > cum[n] - cum[i - 1])
    {
      rem -= cum[n] - cum[i - 1];
      mm--;
      tmp = n - i + 1;
      ll a = min(mm, (rem / cum[n]));
      mm -= a;
      tmp += a * n;
      rem -= a * cum[n];
      if (mm > 0)
      {
        if (rem <= cum[n])
          tmp += coord[rem];
        else
          tmp += n;
      }
    }
    else
    { // cum[n] >= cum[i] + rem
      // cout << 'a' << '\n';
      tmp = coord[cum[i - 1] + rem] - i + 1;
    }
    ans = max(ans, tmp);
  }
  cout << ans << '\n';
  return 0;
}

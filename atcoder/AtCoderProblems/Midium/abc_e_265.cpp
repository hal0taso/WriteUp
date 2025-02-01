#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
ll MOD = 998244353;

int main()
{
  int N, M;
  ll a, b, c, d, e, f;

  cin >> N >> M;
  cin >> a >> b >> c >> d >> e >> f;
  ll x, y;
  set<pair<ll, ll>> prohib;
  REP(i, M)
  {
    cin >> x >> y;
    prohib.insert(make_pair(x, y));
  }
  vector<map<pair<ll, ll>, ll>> dp(N + 1);
  dp[0] = {{make_pair(0, 0), 1}};

  FOR(i, 1, N + 1)
  {
    map<pair<ll, ll>, ll> m;
    for (auto &item : dp[i - 1])
    {
      pair<ll, ll> p = item.first;
      ll cnt = item.second;
      pair<ll, ll> nxt = make_pair(p.first + a, p.second + b);
      if (prohib.find(nxt) == prohib.end())
      {
        m[nxt] += cnt;
        m[nxt] %= MOD;
      }
      nxt = make_pair(p.first + c, p.second + d);
      if (prohib.find(nxt) == prohib.end())
      {
        m[nxt] += cnt;
        m[nxt] %= MOD;
      }
      nxt = make_pair(p.first + e, p.second + f);
      if (prohib.find(nxt) == prohib.end())
      {
        m[nxt] += cnt;
        m[nxt] %= MOD;
      }
    }
    dp[i] = m;
  };
  ll ans = 0;
  for (auto &item : dp[N])
  {
    ans += item.second;
    ans %= MOD;
  }
  cout << ans % MOD << endl;
  return 0;
}

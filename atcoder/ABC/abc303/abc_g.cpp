#include <bits/stdc++.h>
using namespace std;

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
constexpr long long INF = 1000000000000LL;

constexpr int MOD = 1000000000 + 7;

ll f(ll l, ll r, vvll &dp, vvll &flag, vll &a, ll A, ll B, ll C, ll D, vll &acc)
{
  ll n = r - l + 1LL;
  if (l > r)
    return 0LL;
  if (flag[l][r])
  {
    cerr << l << " " << r << " " << n << ' ' << dp[l][r] << '\n';
    return dp[l][r];
  }
  flag[l][r] = 1LL;
  if (l == r)
    return dp[l][r] = a[l];

  return dp[l][r] = max({acc[l + 1] - acc[l] - f(l + 1, r, dp, flag, a, A, B, C, D, acc),
                         acc[r + 1] - acc[r] - f(l, r - 1, dp, flag, a, A, B, C, D, acc),
                         acc[r + 1] - acc[r - min(B, n) + 1] - A - f(l, r - min(B, n), dp, flag, a, A, B, C, D, acc),
                         acc[l + min(B, n)] - acc[l] - A - f(l + min(B, n), r, dp, flag, a, A, B, C, D, acc),
                         acc[r + 1] - acc[r - min(D, n) + 1] - C - f(l, r - min(D, n), dp, flag, a, A, B, C, D, acc),
                         acc[l + min(D, n)] - acc[l] - C - f(l + min(D, n), r, dp, flag, a, A, B, C, D, acc)});
}

int main()
{
  ll n;
  ll A, B, C, D;
  cin >> n;
  cin >> A >> B >> C >> D;
  vector<ll> acc(n + 1, 0);
  vector<ll> a(n);
  REP(i, n)
  {
    cin >> a[i];
    acc[i + 1] += a[i];
    acc[i + 1] += acc[i];
    cerr << acc[i] << ' ';
  }
  cerr << acc[n] << endl;

  vector dp(n, vector<ll>(n, 0));
  vector flag(n, vector<ll>(n, 0));

  cout << f(0, n - 1, dp, flag, a, A, B, C, D, acc) << '\n';

  return 0;
}
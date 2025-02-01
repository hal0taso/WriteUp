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
  int n;
  cin >> n;
  vector<vector<ll>> s(n);
  REP(i, n)
  {
    ll f, si;
    cin >> f >> si;
    f--;
    s[f].push_back(si);
  }
  priority_queue<ll> q;
  REP(i, n)
  {
    sort(all(s[i]));
    reverse(all(s[i]));
    if (s[i].size() > 0)
    {
      q.push(s[i][0]);
    }
  }
  ll ans = 0;
  if (q.size() >= 2)
  {
    REP(i, 2)
    {
      ll tmp = q.top();
      q.pop();
      ans += tmp;
    }
  }
  REP(i, n)
  {
    if (s[i].size() >= 2)
    {
      ll tmp = s[i][0] + s[i][1] / 2LL;
      ans = max(ans, tmp);
    }
  }
  cout << ans << '\n';
  return 0;
}
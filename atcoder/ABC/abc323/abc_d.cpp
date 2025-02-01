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
  int n;
  cin >> n;
  vector<ll> t(n), d(n);
  vector<pair<ll, ll>> r(n + 1);
  REP(i, n)
  {
    cin >> t[i] >> d[i];
    r[i] = {t[i], t[i] + d[i]};
  }
  r[n] = {INF, INF - 1};
  sort(all(r));
  // auto compare = [](pair<ll, ll> a, pair<ll, ll> b)
  // {
  //   return a.second > b.second;
  // };

  ll now = 0, i = 0;
  int ans = 0;
  priority_queue<ll> que;
  now = r[i].first;

  while (i <= n)
  {
    if (now == r[i].first)
    {
      que.push(-r[i].second);
      i++;
      continue;
    }
    while (now < r[i].first && !que.empty())
    {
      ll tmp = -que.top();
      if (now <= tmp)
      {
        ans++;
        now++;
      }
      que.pop();
      ll tmp2 = -que.top();
      debug(tmp2);
    }
    if (que.empty())
    {
      now = r[i].first;
    }
  }
  debug(now);
  cout << ans << endl;
  return 0;
}
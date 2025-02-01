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
  ll n;
  cin >> n;
  vector<ll> a;
  ll x = 1LL;
  REP(i, 17)
  {
    a.push_back(x);
    x *= 10;
    x++;
  }
  // debug(x);
  set<ll> b;
  vector<ll> ans;
  REP(i, 12)
  {
    ll x = a[i];
    REP(j, 12)
    {
      ll y = a[j];
      REP(k, 12)
      {
        ll z = a[k];
        if (b.count(x + y + z) > 0)
          continue;
        b.insert(x + y + z);
        ans.push_back(x + y + z);
      }
    }
  }
  sort(all(ans));
  // REP(i, n)
  // {
  //   debug(a[i]);
  // }
  // REP(i, n)
  // {
  //   debug(ans[i]);
  // }
  cout << ans[n - 1] << endl;
  return 0;
}

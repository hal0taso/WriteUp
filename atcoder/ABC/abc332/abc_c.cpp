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
  vector<ll> a(n);
  REP(i, n)
  cin >> a[i];

  vector<ll> b(n + 1, 0);
  REP(i, n)
  b[i + 1] = a[i];
  sort(all(b));
  vector<ll> acc(n + 1, 0);
  REP(i, n)
  acc[i + 1] = acc[i] + b[i + 1];

  REP(i, n)
  {
    auto pos = upper_bound(all(b), a[i]);

    auto idx = distance(b.begin(), pos);
    cout << acc[n] - acc[idx - 1];

    if (i != n - 1)
      cout << " ";
    else
      cout << endl;
  }
}

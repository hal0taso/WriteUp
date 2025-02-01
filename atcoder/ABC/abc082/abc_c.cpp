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

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  ll ans = 0;
  map<int, int> m;
  REP(i, n)
  {
    cin >> a[i];
    m[a[i]]++;
  }
  for (auto &[key, value] : m)
  {
    if (key <= value)
    {
      ans += value - key;
    }
    else
    {
      ans += value;
    }
  }
  cout << ans << '\n';

  return 0;
}
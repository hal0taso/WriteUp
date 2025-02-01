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
  vector<int> a(n);
  for (auto &x : a)
    cin >> x;
  vector<int> accum = {0};
  REP(i, n)
  {
    if (i % 2 == 1)
    {
      accum.push_back(a[i + 1] - a[i]);
    }
  }
  FOR(i, 1, n / 2 + 1)
  {
    accum[i] += accum[i - 1];
  }

  int q;
  cin >> q;
  while (q > 0)
  {
    int l, r;
    cin >> l >> r;
    int ans = 0;
    auto itrl = lower_bound(all(a), l);
    auto itrr = lower_bound(all(a), r);
    int posl = distance(a.begin(), itrl);
    int posr = distance(a.begin(), itrr);
    if (posl % 2 == 0)
    {
      ans += a[posl] - l;
      posl++;
    }
    if (posr % 2 == 0)
    {
      posr--;
      ans += r - a[posr];
    }
    ans += accum[posr / 2] - accum[posl / 2];
    cout << ans << '\n';
    q--;
  }
  return 0;
}
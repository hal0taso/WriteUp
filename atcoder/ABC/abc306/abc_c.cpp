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
  vector<int> a(3 * n);
  REP(i, 3 * n)
  {
    cin >> a[i];
  }
  vector<int> cnt(n + 1, 0);
  vector<pair<int, int>> v;
  REP(i, 3 * n)
  {
    cnt[a[i]]++;
    if (cnt[a[i]] == 2)
    {
      v.push_back({i, a[i]});
    }
  }
  sort(all(v));
  REP(i, n)
  {
    cout << v[i].second;
    if (i < n - 1)
      cout << ' ';
    else
      cout << '\n';
  }

  return 0;
}
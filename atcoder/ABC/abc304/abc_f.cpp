#include <bits/stdc++.h>
#include <atcoder/modint>

using namespace std;
using namespace atcoder;

using mint = modint998244353;

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
vector<int> divisor(int n)
{
  vector<int> ret;
  for (int i = 1; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      ret.push_back(i);
      if (i * i != n)
        ret.push_back(n / i);
    }
  }
  sort(ret.begin(), ret.end()); // 昇順に並べる
  return ret;
}

int main()
{
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> div = divisor(n);
  mint ans = 0;
  for (int m : div)
  {
    if (m == n)
      break;
    vector<int> cnt(m, 0);
    REP(i, m)
    {
      int x = i;
      while (x < n)
      {
        if (s[x] == '.')
          cnt[i] = 1;
        x += m;
      }
    }
    mint tmp = 1;
    REP(i, m)
    {
      if (cnt[i] == 0)
      {
        tmp *= 2;
      }
    }
    ans += tmp;
    int x = m;
    int d = n / m;

    ans -= max(d - 1, 0) * tmp;
  }
  cout << ans.val() << '\n';
  return 0;
}
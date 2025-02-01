#include <bits/stdc++.h>
#include <atcoder/modint>

using namespace std;
using namespace atcoder;

using mint = modint1000000007;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define RFOR(i, a, b) for (int i = b - 1; i >= a; i--)
#define RREP(i, n) for (int i = n - 1; i >= 0; i--)
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
  string s;
  cin >> s;
  long long n;
  cin >> n;
  reverse(all(s));

  long long m = 0;
  // 実行可能性判定

  ll d = 1;
  REP(i, (int)s.size())
  {
    if (s[i] == '1')
      m += d;
    d <<= 1LL;
  }
  if (m > n)
  {
    cout << -1 << '\n';
    return 0;
  }
  RREP(i, (int)s.size())
  {
    // cout << i << '\n';
    if (s[i] == '?')
    {
      if (m + (1LL << i) <= n)
        m += (1LL << i);
    }
  }
  cout << m << '\n';
  return 0;
}
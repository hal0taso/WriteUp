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
  string s;
  string t;
  cin >> s >> t;
  vector<int> a(26, 0), b(26, 0);
  int p = 0, q = 0;
  set<char> r = {'a', 't', 'c', 'o', 'd', 'e', 'r'};
  for (char u : s)
  {
    if (u != '@')
      a[u - 'a']++;
    else
      p++;
  }
  for (char u : t)
  {
    if (u != '@')
      b[u - 'a']++;
    else
      q++;
  }
  REP(i, 26)
  {
    if (a[i] < b[i] && r.count((char)'a' + i) > 0)
    {
      p -= b[i] - a[i];
    }
    else if (a[i] > b[i] && r.count((char)'a' + i) > 0)
    {
      q -= a[i] - b[i];
    }
    else if (a[i] == b[i])
    {
      continue;
    }
    else
    {
      // cerr << i << a[i] << b[i] << '\n';
      puts("No");
      return 0;
    }
  }
  if (p >= 0 && q >= 0)
    puts("Yes");
  else
    puts("No");

  return 0;
}
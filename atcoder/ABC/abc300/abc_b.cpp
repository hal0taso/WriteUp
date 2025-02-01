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

bool shifteq(vector<string> &a, vector<string> &b, int h, int w, int s, int t)
{
  bool ret = true;
  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      if (a[(i + s) % h][(j + t) % w] != b[i][j])
        ret = false;
    }
  }
  return ret;
}

int main()
{
  int h, w;
  cin >> h >> w;
  vector<string> a(h), b(h);
  REP(i, h)
  cin >> a[i];
  REP(i, h)
  cin >> b[i];
  REP(s, h)
  REP(t, w)
  {
    if (shifteq(a, b, h, w, s, t))
    {
      puts("Yes");
      return 0;
    }
  }
  puts("No");
  return 0;
}
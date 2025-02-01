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
  int n, m, h, k;
  cin >> n >> m >> h >> k;
  map<pair<int, int>, int> f;
  string s;
  cin >> s;
  REP(i, m)
  {
    int xi, yi;
    cin >> xi >> yi;
    f[{xi, yi}]++;
  }
  int x = 0, y = 0;
  int i = 0;
  for (; i < n; i++)
  {
    h--;
    if (h < 0)
      break;

    if (s[i] == 'R')
      x++;
    if (s[i] == 'L')
      x--;
    if (s[i] == 'U')
      y++;
    if (s[i] == 'D')
      y--;

    if (h < k && f[{x, y}] > 0)
    {
      // cnt++;
      f[{x, y}]--;
      h = k;
      // cnt--;
    }
  }
  if (i == n)
  {
    cout << "Yes" << '\n';
  }
  else
  {
    cout << "No" << '\n';
  }
  return 0;
}
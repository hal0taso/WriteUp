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
#define BIT(n, k) (n >> k) & 1
#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vvll = vector<vector<ll>>;
using vll = vector<ll>;
constexpr long long INF = (1LL << 60);

constexpr int MOD = 1000000000 + 7;
using Graph = vector<vector<int>>;
int main()
{
  int n, m;
  cin >> n >> m;
  // Graph G(n);
  map<pair<int, int>, int> w;
  REP(i, m)
  {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    // G[a].push_back(b);
    // G[b].push_back(a);
    w[{a, b}] = c;
    w[{b, a}] = c;
  }
  vector<int> p(n);
  REP(i, n)
  p[i] = i;
  int ans = 0;
  do
  {
    int tmp = 0;
    FOR(i, 1, n)
    {
      if (w[{p[i], p[i - 1]}] > 0)
      {
        tmp += w[{p[i], p[i - 1]}];
      }
      else
      {
        // tmp = -1;
        break;
      }
    }
    ans = max(ans, tmp);
  } while (std::next_permutation(all(p)));
  cout << ans << '\n';

  return 0;
}
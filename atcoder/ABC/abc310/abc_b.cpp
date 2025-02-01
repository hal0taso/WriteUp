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
  int n, m;
  cin >> n >> m;
  vector<int> p(n);
  vector<set<int>> f(n);
  vector<int> c(n);
  REP(i, n)
  {
    cin >> p[i] >> c[i];
    REP(j, c[i])
    {
      int x;
      cin >> x;
      f[i].insert(x);
    }
  }
  string ans = "No";
  REP(i, n)
  {
    REP(j, n)
    {
      bool flag = true;
      if (p[i] >= p[j])
      {
        for (int x : f[i])
        {
          if (f[j].find(x) == f[j].end())
          {
            flag = false;
            break;
          }
        }
        if (flag && (p[i] > p[j] || f[i].size() < f[j].size()))
        {
          ans = "Yes";
        }
      }
    }
  }
  cout << ans << '\n';

  return 0;
}
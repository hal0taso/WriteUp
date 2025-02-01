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
void debug_out()
{
  cerr << endl;
}

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
  cerr << H << " ";
  debug_out(T...);
}

#define debug(...) debug_out(__VA_ARGS__)
constexpr int MOD = 1000000000 + 7;

int main()
{
  int n;
  cin >> n;
  vector<int> d(n + 1);
  FOR(i, 1, n + 1)
  cin >> d[i];

  int ans = 0;
  FOR(i, 1, n + 1)
  {
    bool ok = true;
    int tmp = i % 10;
    if (i >= 10)
    {
      if ((i / 10 % 10) != tmp)
        continue;
    }
    if (i >= 100)
    {
      if ((i / 100 % 10) != tmp)
        continue;
    }
    FOR(j, 1, d[i] + 1)
    {
      if (j % 10 != tmp)
        continue;
      if (j >= 10)
      {
        if ((j / 10 % 10) != tmp)
          continue;
      }
      if (j >= 100)
      {
        if ((j / 100 % 10) != tmp)
          continue;
      }
      if (ok)
        ans++;
    }
  }
  cout << ans << endl;
}

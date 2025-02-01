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
  int h, w, n;
  cin >> h >> w >> n;
  vector<pair<int, int>> d = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  vector<vector<int>> a(h, vector<int>(w, 0));
  int x = 0, y = 0, di = 0;
  REP(i, n)
  {
    if (a[x][y] == 0)
    {
      a[x][y] = 1;
      di = (di + 1) % 4;
    }
    else
    {
      a[x][y] = 0;
      di = (di + 3) % 4;
    }
    x += d[di].first;
    y += d[di].second;
    x += h;
    y += w;
    x %= h;
    y %= w;
  }
  REP(i, h)
  {
    REP(j, w)
    {
      cout << (a[i][j] ? "#" : ".");
    }
    cout << endl;
  }
}

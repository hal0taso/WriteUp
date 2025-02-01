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

bool is_inside(int h, int w, int x, int y, vector<string> &c)
{
  return 0 <= x && x < h && 0 <= y && y < w && c[x][y] != '#';
}

int main()
{
  int h, w;
  cin >> h >> w;
  pair<int, int> s;
  cin >> s.first >> s.second;
  s.first--;
  s.second--;
  vector<string> c(h);
  REP(i, h)
  {
    cin >> c[i];
  }
  string x;
  cin >> x;
  int N = x.size();
  REP(i, N)
  {
    int dx, dy;
    if (x[i] == 'L')
    {
      dx = 0;
      dy = -1;
    }
    else if (x[i] == 'R')
    {
      dx = 0;
      dy = 1;
    }
    else if (x[i] == 'U')
    {
      dx = -1;
      dy = 0;
    }
    else if (x[i] == 'D')
    {
      dx = 1;
      dy = 0;
    }
    if (is_inside(h, w, s.first + dx, s.second + dy, c))
    {
      // debug(i);/*  */
      s.first += dx;
      s.second += dy;
    }
  }
  cout << s.first + 1 << " " << s.second + 1 << endl;
}

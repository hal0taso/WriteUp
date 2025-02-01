#include <bits/stdc++.h>
#include <bit>
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
  int N = 59;
  int a, b;
  cin >> a >> b;
  ull c;
  cin >> c;
  int ci = popcount(c);
  /*   if (a < b)
      swap(a, b); */
  debug(ci);
  vector<int> cb(N, 0);
  REP(i, N)
  {
    if (c & (1LL << i))
    {
      cb[i] = 1;
    }
  }
  int both = a + b - ci;
  if (both % 2 != 0)
  {
    cout << -1 << endl;
    return 0;
  }
  both /= 2;
  // 共有するbit数を求める
  vector<int> ab(N, 0), bb(N, 0);
  REP(i, N)
  {
    if (cb[i] == 1)
    {
      if (a - both > 0)
      {
        ab[i] = 1;
        a--;
        both--;
      }
      else if (b - both > 0)
      {
        bb[i] = 1;
        b--;
        both--;
      }
      else
      {
        cout << -1 << endl;
        return 0;
      }
      ci--;
    }
    else
    {
      if (both > 0)
      {
        if (a > 0 && b > 0)
        {
          ab[i] = 1;
          bb[i] = 1;
          a--, b--;
          both--;
        }
        else
        {
          cout << -1 << endl;
          return 0;
        }
      }
    }
  }
  ull x = 0, y = 0;
  REP(i, N)
  {
    x += ab[i] * (1LL << i);
    y += bb[i] * (1LL << i);
  }
  if (x ^ y == c)
    cout << x << " " << y << endl;
  else
    cout << -1 << endl;
}

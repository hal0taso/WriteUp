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

bool f(int i, int j, int dx, int dy, vector<string> &S, string &t)
{
  int n = t.size();

  string p = "";
  if (i + (n - 1) * dx >= 0 && i + (n - 1) * dx < S.size())
  {
    if (j + (n - 1) * dy >= 0 && j + (n - 1) * dy < S[i].size())
    {
      for (int k = 0; k < n; k++)
      {
        p += S[i][j];
        i += dx;
        j += dy;
      }
    }
  }
  // cerr << i << "," << j << "|" << dx << "," << dy << "|" << t << '\n';
  // cerr << i << "," << j << "|" << dx << "," << dy << "|" << p << '\n';

  return t == p;
}

int main()
{
  int h, w;
  cin >> h >> w;
  vector<string> S(h);
  for (string &s : S)
    cin >> s;
  string t = "snuke";
  int n = t.size();
  vector<pair<int, int>> ans(n);
  REP(i, h)
  {
    REP(j, w)
    {
      for (int dx : {-1, 0, 1})
      {
        for (int dy : {-1, 0, 1})
        {
          if (f(i, j, dx, dy, S, t))
          {
            int x = i, y = j;
            REP(k, n)
            {
              cout << x + 1 << " " << y + 1 << '\n';
              x += dx, y += dy;
            }
            return 0;
          }
        }
      }
    }
  }
  return 0;
}
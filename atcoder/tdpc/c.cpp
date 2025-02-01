#include <bits/stdc++.h>
#include <functional>
using namespace std;

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

int main()
{
  int k;
  cin >> k;
  int N = 1 << k;
  vector<int> R(N);
  for (auto &x : R)
    cin >> x;
  vector<vector<double>> dp(N, vector<double>(2 * N, 0));
  /*
  h| v
  0| 1
  1| 2 3
  2| 4 5 6 7
  3| 8 9 10 11 12 13 14 15
  4| 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31
  */
  REP(i, N)
  {
    dp[i][N + i] = 1.0;
    // cerr << i << "|" << N + i << "|" << dp[i][N + i] << '\n';
  }

  vector<vector<double>> p(N, vector<double>(N, 0.));
  REP(i, N)
  {
    REP(j, N)
    {
      p[i][j] = 1. / (1. + pow(10., (double)(R[j] - R[i]) / 400.));
    }
  }

  RREP(h, k) // O(k)
  {
    FOR(v, 1 << h, 1 << (h + 1)) // O(2^{k+1})
    {
      int l = (v << 1) | 0;
      int r = (v << 1) | 1;

      int w = 1 << (k - h - 1);
      int sl = (l - (1 << (h + 1))) * w, tl = (l - (1 << (h + 1)) + 1) * w;
      int sr = (r - (1 << (h + 1))) * w, tr = (r - (1 << (h + 1)) + 1) * w;
      FOR(i, sl, tl) // amortized O(2^k+1)
      {
        FOR(j, sr, tr)
        {
          dp[i][v] += p[i][j] * dp[j][r] * dp[i][l];
          dp[j][v] += p[j][i] * dp[j][r] * dp[i][l];
        }
      }
    }
  }
  cout << fixed << setprecision(10);
  REP(i, N)
  {
    cout << dp[i][1] << '\n';
  }
  return 0;
}

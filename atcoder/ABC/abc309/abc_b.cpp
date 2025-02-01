#include <bits/stdc++.h>
// #include <atcoder/modint>

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

constexpr int MOD = 1000000000 + 7;

int main()
{
  int n;
  cin >> n;

  vector a(n, vector<int>(n, 0));
  string s;
  REP(i, n)
  {
    cin >> s;
    REP(j, n)
    {

      a[i][j] = s[j] - '0';
    }
  }
  vector b(n, vector<int>(n, 0));
  REP(i, n)
  {
    REP(j, n)
    {
      b[i][j] = a[i][j];
    }
  }

  REP(i, n - 1)
  {
    b[0][i + 1] = a[0][i];
    b[i + 1][n - 1] = a[i][n - 1];
  }
  FOR(i, 1, n)
  {
    b[n - 1][n - 1 - i] = a[n - 1][n - i];
    b[n - 1 - i][0] = a[n - i][0];
  }
  REP(i, n)
  {
    REP(j, n)
    {
      cout << b[i][j];
    }
    cout << '\n';
  }

  return 0;
}
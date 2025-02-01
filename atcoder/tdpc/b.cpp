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

pair<int, int> func(int i, int j, vector<int> &A, vector<int> &B, vector<vector<pair<int, int>>> &dp, vector<vector<int>> &seen)
{
  int n = A.size(), m = B.size();
  i = min(i, n);
  j = min(j, m);
  if (seen[i][j])
  {
    // cerr << i << "|" << j << "|" << dp[i][j].first << "-" << dp[i][j].second << '\n';
    return dp[i][j];
  }
  seen[i][j] = 1;
  if (i >= n && j >= m)
  {

    return {0, 0};
  }
  if (i >= n)
  {

    return dp[n][j] = {-func(i, j + 1, A, B, dp, seen).second + B[j], -func(i, j + 1, A, B, dp, seen).first};
  }
  if (j >= m)
  {

    return dp[i][m] = {-func(i + 1, j, A, B, dp, seen).second + A[i], -func(i + 1, j, A, B, dp, seen).first};
  }

  return dp[i][j] = max(make_pair<int, int>(-func(i + 1, j, A, B, dp, seen).second + A[i], -func(i + 1, j, A, B, dp, seen).first),
                        make_pair<int, int>(-func(i, j + 1, A, B, dp, seen).second + B[j], -func(i, j + 1, A, B, dp, seen).first));
}

int main()
{
  int a, b;
  cin >> a >> b;
  vector<int> A(a), B(b);
  for (auto &x : A)
    cin >> x;
  for (auto &x : B)
    cin >> x;

  vector dp(a + 1, vector<pair<int, int>>(b + 1, {0, 0}));
  vector seen(a + 2, vector<int>(b + 2, 0));

  cout << func(0, 0, A, B, dp, seen).first << '\n';

  return 0;
}

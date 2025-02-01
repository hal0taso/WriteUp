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
  string s;
  cin >> n >> s;
  map<char, int> mp;
  vector<int> a(n + 1, 3);
  mp['R'] = 0;
  mp['P'] = 1;
  mp['S'] = 2;
  FOR(i, 1, n + 1)
  {
    a[i] = mp[s[i - 1]];
  }
  vector dp(n + 1, vector(3, 0));
  FOR(i, 1, n + 1)
  {
    if (a[i] == mp['R']) // 'R'
    {
      dp[i][mp['P']] = max(dp[i - 1][mp['S']], dp[i - 1][mp['R']]) + 1;
      dp[i][mp['R']] = max(dp[i - 1][mp['S']], dp[i - 1][mp['P']]);
    }
    else if (a[i] == mp['P'])
    {
      dp[i][mp['S']] = max(dp[i - 1][mp['R']], dp[i - 1][mp['P']]) + 1;
      dp[i][mp['P']] = max(dp[i - 1][mp['S']], dp[i - 1][mp['R']]);
    }
    else // a[i] = 'S'
    {
      dp[i][mp['R']] = max(dp[i - 1][mp['S']], dp[i - 1][mp['P']]) + 1;
      dp[i][mp['S']] = max(dp[i - 1][mp['R']], dp[i - 1][mp['P']]);
    }
  }
  cout << max(dp[n][mp['R']], max(dp[n][mp['P']], dp[n][mp['S']])) << endl;
}

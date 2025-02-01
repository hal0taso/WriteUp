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
using Graph = vector<vector<int>>;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<string> S(n);
  for (auto &s : S)
    cin >> s;
  vector<vector<int>> diff(n, vector<int>(n, 0));
  REP(i, n)
  REP(j, n)
  {
    int cnt = 0;
    REP(k, m)
    if (S[i][k] != S[j][k])
      cnt++;
    diff[i][j] = cnt;
  }
  vector<int> p(n);
  REP(i, n)
  {
    p[i] = i;
  }
  bool ans = false;
  do
  {
    bool f = true;
    REP(i, n - 1)
    {
      if (diff[p[i]][p[i + 1]] != 1)
      {
        f = false;
        break;
      }
    }
    ans |= f;
  } while (std::next_permutation(p.begin(), p.end()));
  if (ans)
    puts("Yes");
  else
    puts("No");
  return 0;
}
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

bool judge(int n, int m, ll w, vector<ll> acc)
{
  ll base = 0;
  REP(i, m - 1)
  {
    auto it = upper_bound(all(acc), base + w); // 最後に空白あるかもなので+1
    if (it == acc.end())
    {
      break;
    }
    size_t pos = distance(acc.begin(), it);
    pos--;
    // debug(w, base + w, i, pos);
    base = acc[pos];
  }
  // debug("base", base);
  if (base + w < acc[n])
    return false;
  else
    return true;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<ll> L(n + 1, 0);

  REP(i, n)
  cin >> L[i + 1], L[i + 1]++;

  vector<ll> acc(n + 1, 0);
  FOR(i, 1, n + 1)
  {
    acc[i] = acc[i - 1] + L[i];
    // debug("acc", i, acc[i]);
  }

  // w を探索
  ll ub = acc[n];
  ll lb = 1;
  while (lb + 1 < ub)
  {
    ll w = (ub + lb) / 2;
    if (judge(n, m, w, acc))
    {
      ub = w;
    }
    else
    {
      lb = w;
    }
  }

  cout << ub - 1 << '\n';

  return 0;
}
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
  cin >> n;
  string s;
  cin >> s;
  sort(all(s));

  vector<ll> square;
  ll i = 0;
  ll maxint = 1;
  REP(i, n)
  {
    maxint *= 10;
  }
  while (i * i <= maxint)
  {
    square.push_back(i * i);
    i++;
  }
  vector<string> S;
  for (ll s1 : square)
  {
    string s2 = to_string(s1);
    s2 = string(max(0, n - (int)s2.size()), '0') + s2;
    sort(all(s2));
    S.push_back(s2);
  }
  ll ans = 0;
  for (string s2 : S)
  {
    if (s == s2)
      ans++;
  }
  cout << ans << '\n';

  return 0;
}
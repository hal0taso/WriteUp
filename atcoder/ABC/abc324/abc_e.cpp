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

int prefix(string &s, string &t)
{
  int n = s.size();
  int m = t.size();
  int j = 0;
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    if (j >= m)
      break;
    if (s[i] == t[j])
      j++, ans++;
  }
  return ans;
}

int suffix(string &s, string &t)
{
  int n = s.size();
  int m = t.size();
  int j = m - 1;
  int ans = 0;
  for (int i = n - 1; i >= 0; i--)
  {
    if (j < 0)
      break;
    if (s[i] == t[j])
      j--, ans++;
  }
  return ans;
}
int main()
{
  int n;
  cin >> n;
  string t;
  cin >> t;
  vector<string> s(n);
  REP(i, n)
  {
    cin >> s[i];
  }
  vector<int> a(n), b(n);
  REP(i, n)
  {
    a[i] = prefix(s[i], t);
    b[i] = suffix(s[i], t);
  }
  sort(all(a));
  sort(all(b));
  int m = t.size();
  ll ans = 0;
  REP(i, n)
  {
    if (a[i] == m)
    {
      ans += n;
      continue;
    }
    int idx = lower_bound(all(b), m - a[i]) - b.begin();
    ans += n - idx;
  }
  cout << ans << endl;

  return 0;
}
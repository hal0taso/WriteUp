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

int main()
{
  int n;
  cin >> n;
  vector<string> s(n);
  vector<string> t(n);
  set<string> k;
  REP(i, n)
  {
    cin >> s[i];
    t[i] = s[i];
    reverse(all(t[i]));
  }
  REP(i, n)
  {
    string tmp = s[i];
    if (s[i] > t[i])
    {
      tmp = t[i];
    }
    k.insert(tmp);
  }
  cout << k.size() << '\n';
  return 0;
}
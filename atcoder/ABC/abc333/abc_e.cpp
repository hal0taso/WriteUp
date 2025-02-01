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
  vector<pair<int, int>> p;
  REP(i, n)
  {
    int x, y;
    cin >> x >> y;
    p.push_back({x, y});
  }
  reverse(all(p));
  vector<int> ans;
  int m = 0;
  int c = 0;
  map<int, int> mp;
  REP(i, n)
  {
    int x = p[i].first;
    int y = p[i].second;
    if (x == 2)
    {
      mp[y]++;
      c++;
      m = max(c, m);
    }
    else
    {
      if (mp[y] > 0)
      {
        ans.push_back(1);
        mp[y]--;
        c--;
      }
      else
      {
        ans.push_back(0);
      }
    }
  }
  REP(i, n + 1)
  {
    if (mp[i] > 0)
    {
      m = -1;
    }
  }
  reverse(all(ans));
  cout << m << endl;
  if (m >= 0)
  {
    REP(i, ans.size())
    {
      cout << ans[i];
      if (i < ans.size() - 1)
      {
        cout << " ";
      }
      else
      {
        cout << endl;
      }
    }
  }
}

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
  string t;
  cin >> t;
  vector<string> S(n);
  REP(i, n)
  cin >> S[i];
  int m = t.size();
  vector<int> ans;
  REP(i, n)
  {
    int same = 0;
    int cnt = 0;
    int left = 0, right = 0;
    int m2 = S[i].size();
    if (m + 1 == m2)
      left = 1;
    else if (m == m2 + 1)
      right = 1;
    else if (m == m2)
      left = 0, right = 0;
    else
      continue;
    REP(j, m)
    {
      if (t[j + same * right] != S[i][j + same * left])
      {
        cnt++;
        if (same == 0 && left + right > 0)
          j--;
        same = 1;
      }
    }
    if (cnt <= 1)
    {
      ans.push_back(i + 1);
    }
  }
  cout << ans.size() << endl;
  REP(i, ans.size())
  {
    if (i < ans.size() - 1)
      cout << ans[i] << ' ';
    else
      cout << ans[i] << endl;
  }

  return 0;
}
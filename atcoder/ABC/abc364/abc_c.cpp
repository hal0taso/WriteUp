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

bool is_palindrome(string s)
{
  int n = s.size();
  REP(i, n / 2)
  {
    if (s[i] != s[n - i - 1])
    {
      return false;
    }
  }
  return true;
}

int main()
{
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  sort(all(s));
  int ans = 0;
  do
  {
    bool flag = true;
    REP(i, n - k + 1)
    {
      string t = s.substr(i, k);
      if (is_palindrome(t))
      {
        flag = false;
        break;
      }
    }
    if (flag)
    {
      ans++;
    }
  } while (next_permutation(all(s)));
  cout << ans << endl;
}

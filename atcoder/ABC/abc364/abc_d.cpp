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

long long pow(long long a, long long b)
{
  long long res = 1;
  for (long long i = 0; i < b; i++)
  {
    res *= a;
  }
  return res;
}

int main()
{
  long long n;
  cin >> n;
  string ans = "";
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }
  long long rem = n-1;
  // input: n
  // output: n-th parindrome number x
  // 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, : 10(10)
  // 11, 22, 33, 44, 55, 66, 77, 88, 99 : 9(19)
  // 101, 111, 121, 131, 141, 151, 161, 171, 181, 191 : 10(29)
  // 202, 212, 222, 232, 242, 252, 262, 272, 282, 292 : 10(38)
  // 303, 313, 323, 333, 343, 353, 363, 373, 383, 393 : 10


  // はじめにxの長さを決める
  // 1桁の場合は 9+1=10個
  // 2桁の場合は 9個
  // 3桁の場合は 9 * 10 = 90個
  // 4桁の場合は 9 * 10 = 90個
  // l桁の場合は 9 * 10 ^ (l-1)/2 個
  long long l = 1;
  ll tmp = 0;
  while (rem > 9LL * pow(10LL, (l-1LL)/2LL)) {
    tmp = 9LL * pow(10LL, (l-1LL)/2LL);
    // debug("", rem, tmp, l);
    rem -= tmp;
    l++;
  }
  debug("l", rem, tmp, l);
  tmp = 0;
  // 先頭を決める. 2文字目以降, 1増やすごとに 10^(l-1)/2 だけ増える
  FOR(i, 1, 10) {
    // debug(tmp);
    if (tmp + pow(10LL, (l-1LL)/2LL) >= rem) {
      // debug("1", rem, tmp, i);
      ans += '0' + i;
      break;
    }
    tmp += pow(10LL, (l-1LL)/2LL);
  }
  rem -= tmp;
  tmp = 0;
  // 2文字目以降を決める. 1増やすごとに 10^残り文字数 だけ増える
  RFOR(k, 0, (l-1LL)/2LL) {
    tmp = 0;
    FOR(i, 0, 10) {
      if (tmp + pow(10LL, k) >= rem) {
        // debug((l-1)/2 + 1 - k, rem, tmp, i);
        ans += '0' + i;
        break;
      }
      tmp += pow(10LL, k);
    }
    rem -= tmp;
  }
  // debug(rem);
  string tmps = ans;
  reverse(all(tmps));
  if (l % 2 == 0) {
    ans += tmps;
  } else {
    ans += tmps.substr(1, tmps.size()-1);
  }
  cout << ans << endl;

}

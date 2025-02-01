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
constexpr long long MOD = 998244353;

int main()
{
  long long n, m;
  cin >> n >> m;
  int N = 60;
  vector<int> a(N, 0), b(N, 0);
  REP(i, N){
    a[i] = (n >> i) & 1;
    b[i] = (m >> i) & 1;
  }
  long long ans = 0;
  REP(i, N){
    if (b[i] == 1)
    {
     ans += n / (1LL << (i+1)) * (1LL << i);
     ans %= MOD;
     ans += max(n % (1LL << (i + 1)) - (1LL << i) + 1LL, 0LL); 
     ans %= MOD;
    }
  }
  cout << ans << endl;

}

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

// 1 以上 N 以下の整数が素数かどうかを返す
vector<bool> Eratosthenes(int N)
{
  // テーブル
  vector<bool> isprime(N + 1, true);

  // 1 は予めふるい落としておく
  isprime[1] = false;

  // ふるい
  for (int p = 2; p <= N; ++p)
  {
    // すでに合成数であるものはスキップする
    if (!isprime[p])
      continue;

    // p 以外の p の倍数から素数ラベルを剥奪
    for (int q = p * 2; q <= N; q += p)
    {
      isprime[q] = false;
    }
  }

  // 1 以上 N 以下の整数が素数かどうか
  return isprime;
}
int main()
{
  ll n;
  cin >> n;
  ll ans = 0;
  ll N = 2;
  while (N * N < n)
  {
    N++;
  }
  vector<bool> isprime = Eratosthenes(N);
  vector<ll> prime;
  FOR(i, 2, N + 1)
  {
    if (isprime[i])
      prime.push_back(i);
  }
  int m = prime.size();
  REP(i, m - 2)
  {
    ll a = prime[i];
    if (a * a > n)
      break;
    FOR(j, i + 1, m - 1)
    {
      ll b = prime[j];
      if (a * a * b > n)
        break;
      FOR(k, j + 1, m)
      {
        ll c = prime[k];
        if (a * a * b > n / (c * c))
          break;

        if (a * a * b * c * c <= n)
        {
          ans++;
        }
        else
        {
          break;
        }
      }
    }
  }
  cout << ans << '\n';
}
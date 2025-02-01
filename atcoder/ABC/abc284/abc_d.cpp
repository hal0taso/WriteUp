#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)

vector<ll> prime;
std::vector<bool> Eratosthenes(ll N)
{
  // テーブル
  std::vector<bool> isprime(N + 1, true);

  // 0, 1 は予めふるい落としておく
  isprime[0] = isprime[1] = false;

  // ふるい
  for (ll p = 2; p <= N; ++p)
  {
    // すでに合成数であるものはスキップする
    if (!isprime[p])
      continue;
    prime.push_back(p);
    // p 以外の p の倍数から素数ラベルを剥奪
    for (ll q = p * 2; q <= N; q += p)
    {
      isprime[q] = false;
    }
  }

  // 1 以上 N 以下の整数が素数かどうか
  return isprime;
}

int main()
{
  int t;
  cin >> t;
  ll N = 0;
  vector<ll> v(t);
  REP(i, t)
  {
    cin >> v[i];
  }

  vector<bool> is_prime = Eratosthenes(3000000LL);
  // cout << "{";
  // for (ll p : prime)
  //   cout << p << ',';
  // cout << "}\n";
  // FOR(p, 2, N + 1)
  // {
  //   if (is_prime[p])
  //     prime.push_back(p);
  // }
  reverse(prime.begin(), prime.end());
  REP(i, t)
  {
    ll n = v[i];
    for (ll p : prime)
    {
      if (n % p == 0)
      {
        if (n % (p * p) == 0)
          cout << p << ' ' << n / (p * p) << endl;
        else
          cout << (ll)sqrt(n / p) << ' ' << p << endl;
        break;
      }
    }
  }
  return 0;
}

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll powmod(ll a, ll b, ll mod) {
  ll res = 1;
  for (; b; b >>= 1) {
    if (b & 1) {
      res = res * a % mod;
    }
    a = a * a % mod;
  }
  return res;
}

int main() {
  ull n;
  cin >> n;
  ll res = 0;
  ll mod = 1000000007;
  if (n > 1) {
    res = powmod(10, n, mod);
    res = (res - powmod(9, n, mod)) % mod;
    res = (res - powmod(9, n, mod)) % mod;
    res = (res + powmod(8, n, mod)) % mod;
  }
  if (res < 0) {
    res += mod;
  }
  cout << res << endl;
}

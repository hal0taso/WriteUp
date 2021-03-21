#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)

#define MOD 1000000007

int main() {
  ll n, ans = 1;
  cin >> n;
  for (ll i = n; i >= 1; i--) {
    ans *= i;
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)

int main() {
  long long n;
  cin >> n;
  long long ans = n - 1;
  for (ll i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      if (i - 1 + n / i - 1 < ans) {
        ans = i - 1 + n / i - 1;
      }
    }
  }
  cout << ans << endl;
  return 0;
}

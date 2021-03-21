#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)

int main() {
  int n, ans = 0, ai, j;
  cin >> n;
  REP(i, n) {
    cin >> ai;
    for (j = 0; ai % 2 == 0; j++) {
      ai >>= 1;
    }
    ans += j;
  }
  cout << ans << endl;

  return 0;
}

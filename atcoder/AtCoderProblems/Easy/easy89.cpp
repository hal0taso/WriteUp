#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)

int main() {
  ull x, y, ans = 0;
  cin >> x >> y;
  while (x <= y) {
    ans++;
    x <<= 1;
  }
  cout << ans << endl;
  return 0;
}

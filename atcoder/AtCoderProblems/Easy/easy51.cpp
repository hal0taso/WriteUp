#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)
int main() {
  int n, a, b, res, ans = 0;
  cin >> n >> a >> b;
  FOR(i, 1, n + 1) {
    string c = to_string(i);
    res = 0;
    for (auto ci : c) {
      res += ci - '0';
    }
    if (res >= a & res <= b) {
      ans += i;
    }
  }
  cout << ans << endl;
  return 0;
}

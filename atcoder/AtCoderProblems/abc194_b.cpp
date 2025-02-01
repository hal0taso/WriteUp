#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  int n, t, ans = 1000000;
  cin >> n;
  vector<int> a(n), b(n);
  REP(i, n) { cin >> a[i] >> b[i]; }
  REP(i, n) {
    REP(j, n) {
      if (i == j) {
        t = a[i] + b[j];
      } else {
        t = max(a[i], b[j]);
      }
      if (ans > t) {
        ans = t;
      }
    }
  }
  cout << ans << endl;
}

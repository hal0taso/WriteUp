#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  int n, d, ans = 0;
  int vi, norm, diff;
  cin >> n >> d;
  vector<vector<int>> X(n, vector<int>(d));
  REP(i, n) {
    REP(j, d) { cin >> X[i][j]; }
  }
  REP(i, n) {
    FOR(j, i + 1, n) {
      norm = 0;
      REP(k, d) {
        diff = abs(X[i][k] - X[j][k]);
        norm += diff * diff;
      }
      for (int k = 0; k * k <= norm; ++k) {
        if (k * k == norm)
          ans++;
      }
    }
  }
  cout << ans << endl;

  return 0;
}

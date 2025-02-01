#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  vector<vector<int>> c(3, vector<int>(3));
  bool ans = true;
  REP(i, 3) {
    REP(j, 3) { cin >> c[i][j]; }
  }
  FOR(i, 1, 3) {
    REP(j, 2) { ans &= (c[i][j] - c[i][j + 1]) == (c[0][j] - c[0][j + 1]); }
  }
  FOR(i, 1, 3) {
    REP(j, 2) { ans &= (c[j][i] - c[j + 1][i]) == (c[j][0] - c[j + 1][0]); }
  }
  if (ans)
    puts("Yes");
  else
    puts("No");

  return 0;
}

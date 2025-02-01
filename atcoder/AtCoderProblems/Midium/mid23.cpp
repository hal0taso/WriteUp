#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  int n, m, s, c;
  cin >> n >> m;
  vector<int> ans(n, -1);
  REP(i, m) {
    cin >> s >> c;
    if (ans[s - 1] == -1) {
      ans[s - 1] = c;
    } else if (ans[s - 1] != c) {
      cout << -1 << endl;
      return 0;
    }
  }
  if (n > 1) {
    if (ans[0] == 0) {
      cout << -1 << endl;
      return 0;
    } else if (ans[0] < 0) {
      ans[0] = 1;
    }
  }
  REP(i, n) {
    if (ans[i] < 0)
      ans[i] = 0;
    cout << ans[i];
  }
  cout << endl;

  return 0;
}

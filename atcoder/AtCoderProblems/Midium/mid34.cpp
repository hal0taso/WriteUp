#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  int n, k, ai;
  cin >> n >> k;
  int idx;
  FOR(i, 1, n + 1) {
    cin >> ai;
    if (ai == 1) {
      idx = i;
    }
  }
  int ans = n;
  FOR(i, 1, k + 1) {
    int r = idx - i, l = n - (k - i) - idx;
    ans = min(ans, (r + k - 2) / (k - 1) + (l + k - 2) / (k - 1) + 1);
  }
  cout << ans << endl;

  return 0;
}

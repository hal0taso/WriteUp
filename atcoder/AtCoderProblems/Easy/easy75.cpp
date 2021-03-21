#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  int n, k, ans = 1000000000;
  cin >> n >> k;
  vector<int> h(n);
  REP(i, n) { cin >> h[i]; }
  sort(h.begin(), h.end());
  for (int i = 0; i + k - 1 < n; i++) {
    if (h[i + k - 1] - h[i] < ans) {
      ans = h[i + k - 1] - h[i];
    }
  }
  cout << ans << endl;
  return 0;
}

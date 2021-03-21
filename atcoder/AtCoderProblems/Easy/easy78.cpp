#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  REP(i, n) { cin >> h[i]; }
  REP(i, n - 1) {
    if (h[n - 1 - i] - h[n - 2 - i] == -1) {
      h[n - 2 - i]--;
    } else if (h[n - 1 - i] - h[n - 2 - i] >= 0) {
      continue;
    } else {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}

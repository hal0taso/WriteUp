#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  int n;
  string s, t;
  cin >> n >> s >> t;
  int ans = 0;
  FOR(i, 1, n + 1) {
    if (s.substr(n - i, i) == t.substr(0, i)) {
      if (ans < i) {
        ans = i;
      }
    }
  }
  cout << 2 * n - ans << endl;
  return 0;
}

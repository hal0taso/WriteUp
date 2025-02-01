#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  int s, t;
  cin >> s >> t;
  int ans = 0;
  REP(a, s + 1) {
    REP(b, s - a + 1) {
      REP(c, s - a - b + 1) {
        if (a * b * c <= t) {
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
}

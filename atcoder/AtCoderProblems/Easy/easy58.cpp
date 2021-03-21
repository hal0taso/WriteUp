#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  long n, ans = 1;
  double diff, h, t, a;
  cin >> n;
  cin >> t >> a;
  diff = 10000000;
  REP(i, n) {
    cin >> h;
    if (abs(t - h * 0.006 - a) < diff) {
      diff = abs(t - h * 0.006 - a);
      ans = i + 1;
    }
  }
  cout << ans << endl;
  return 0;
}

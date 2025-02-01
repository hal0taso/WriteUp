#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  int n, prev, cur, ans = 1;

  bool inc = false, dec = false;

  cin >> n;
  cin >> prev;
  REP(i, n - 1) {
    cin >> cur;
    if (prev > cur) {
      if (!(inc | dec))
        dec = true;
      else if (inc) {
        ans++;
        inc = false;
      }
    }
    if (prev < cur) {
      if (!(inc | dec))
        inc = true;
      else if (dec) {
        ans++;
        dec = false;
      }
    }
    prev = cur;
  }
  cout << ans << endl;
  return 0;
}

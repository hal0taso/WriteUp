#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)

int main() {
  int n, ui, li, usum = 0, lsum = 0, ans = 0;
  cin >> n;
  vector<int> u(n);
  vector<int> l(n);
  REP(i, n) {
    cin >> ui;
    usum += ui;
    u[i] = usum;
  }
  REP(i, n) { cin >> l[i]; }
  REP(i, n) {
    lsum += l[n - 1 - i];
    l[n - 1 - i] = lsum;
  }
  REP(i, n) {
    if (u[i] + l[i] > ans)
      ans = u[i] + l[i];
  }

  cout << ans << endl;
  return 0;
}

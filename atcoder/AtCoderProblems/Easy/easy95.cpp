#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

#define MOD 1000000007

int main() {
  vector<int> a(3);
  int cnt = 0, ans = 0;
  REP(i, 3) { cin >> a[i]; }
  sort(a.begin(), a.end());
  if (!(a[0] % 2 == a[1] % 2 && a[1] % 2 == a[2] % 2)) {
    REP(i, 3) {
      if (a[i % 3] % 2 == a[(i + 1) % 3] % 2 &&
          a[(i + 1) % 3] % 2 != a[(i + 2) % 3] % 2) {
        a[i % 3]++;
        a[(i + 1) % 3]++;
        ans++;
        break;
      }
    }
  }
  ans += ((a[2] - a[1]) + (a[2] - a[0])) / 2;
  cout << ans << endl;
  return 0;
}

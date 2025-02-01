#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  int n, ans = 0;
  cin >> n;
  vector<int> s(n);

  REP(i, n) {
    cin >> s[i];
    ans += s[i];
  }
  sort(s.begin(), s.end());
  if (ans % 10 == 0) {
    REP(i, n) {
      if (s[i] % 10 != 0) {
        ans -= s[i];
        cout << ans << endl;
        return 0;
      }
    }
    cout << 0 << endl;
  } else {
    cout << ans << endl;
  }

  return 0;
}

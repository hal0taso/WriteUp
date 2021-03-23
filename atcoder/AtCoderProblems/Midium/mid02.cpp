#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  ll cnt = 0, ans = 0, n;
  string s;
  cin >> s;
  n = s.size();
  REP(i, n) {
    if (s[i] == 'B') {
      ans += n - (i + 1) - cnt;
      cnt++;
    }
  }
  cout << ans << endl;

  return 0;
}

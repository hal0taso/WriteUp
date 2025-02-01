#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  string s;
  cin >> s;
  int cur = 0;
  vector<int> ans(10, -1);
  REP(i, s.size()) {
    if (s[i] != 'B') {
      ans[cur] = s[i] - '0';
      cur++;
    } else if (cur > 0) {
      cur--;
      ans[cur] = -1;
    }
  }
  REP(i, 10) {
    if (ans[i] == -1)
      break;
    cout << ans[i];
  }
  cout << endl;

  return 0;
}

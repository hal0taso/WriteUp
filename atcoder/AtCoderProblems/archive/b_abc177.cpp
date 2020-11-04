#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
typedef long long ll;

int main() {
  string s, t;
  int ans = 1e9;
  cin >> s >> t;
  REP(i, s.size()) {
    if (i + t.size() > s.size())
      break;
    int cnt = 0;
    REP(j, t.size()) {
      if (s[i + j] != t[j])
        cnt++;
    }
    ans = min(ans, cnt);
  }
  cout << ans << endl;
  return 0;
}

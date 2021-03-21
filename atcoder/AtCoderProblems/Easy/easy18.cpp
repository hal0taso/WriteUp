#include <iostream>
#include <string>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  string s;
  cin >> s;
  string tgt = "ACGT";
  int cnt = 0;
  int ans = 0;
  REP(i, s.size()) {
    if (tgt.find(s[i]) != string::npos) {
      cnt++;
    } else {
      if (ans < cnt) {
        ans = cnt;
      }
      cnt = 0;
    }
  }
  if (ans < cnt) {
    ans = cnt;
  }
  cout << ans << endl;
}

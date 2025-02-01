#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  string s, t;
  int n;
  cin >> n;
  cin >> s >> t;
  vector<int> szero;
  vector<int> tzero;
  REP(i, n) {
    if (s[i] - '0' == 0) {
      szero.push_back(i);
    }
    if (t[i] - '0' == 0) {
      tzero.push_back(i);
    }
  }

  if (szero.size() != tzero.size()) {
    cout << -1 << endl;
    return 0;
  }
  int length = szero.size();
  int ans = 0;
  REP(i, length) {
    if (szero[i] != tzero[i]) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}

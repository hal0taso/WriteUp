#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  string s, s1, s2;
  cin >> s;
  int n = s.size(), ans;
  for (int i = (n - 1) / 2; i > 0; i--) {
    s1 = s.substr(0, i);
    s2 = s.substr(i, i);
    if (s1 == s2) {
      cout << 2 * i << endl;
      break;
    }
  }

  return 0;
}

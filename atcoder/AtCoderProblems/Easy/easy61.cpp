#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  string s, t;
  cin >> s >> t;
  int n = s.size();
  REP(i, n) {
    if (s == t) {
      puts("Yes");
      return 0;
    }
    s = s[n - 1] + s.substr(0, n - 1);
  }
  puts("No");
  return 0;
}

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
  bool flg;
  int c, cnt = 0;
  flg = s[0] == 'A';
  FOR(i, 2, s.size() - 1) {
    if (s[i] == 'C') {
      cnt++;
      c = i;
    }
  }
  flg &= cnt == 1;
  FOR(i, 1, s.size()) {
    if (i == c)
      continue;
    flg &= s[i] - 'a' >= 0;
  }
  if (flg)
    puts("AC");
  else
    puts("WA");

  return 0;
}

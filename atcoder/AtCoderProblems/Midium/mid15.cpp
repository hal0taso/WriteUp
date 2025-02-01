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
  string keyence = "keyence";
  int b, c = 0;
  REP(i, s.size()) {
    if (c >= 7) {
      puts("YES");
      return 0;
    }
    if (s[i] != keyence[c]) {
      b = i;
      break;
    }
    c++;
  }
  if (c >= 7) {
    puts("YES");
    return 0;
  }
  int pos = s.rfind(keyence.substr(c, 7 - c));
  if (pos + 7 - c == s.size())
    puts("YES");
  else
    puts("NO");
  return 0;
}

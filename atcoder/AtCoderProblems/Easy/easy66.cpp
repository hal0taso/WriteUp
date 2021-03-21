#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  string str;
  cin >> str;
  int n = 0, w = 0, s = 0, e = 0;
  for (auto si : str) {
    if (si == 'N') {
      n++;
    } else if (si == 'W') {
      w++;
    } else if (si == 'S') {
      s++;
    } else if (si == 'E') {
      e++;
    }
  }
  if ((n * s > 0 | n + s == 0) & (w * e > 0 | w + e == 0)) {
    puts("Yes");
  } else {
    puts("No");
  }
  return 0;
}

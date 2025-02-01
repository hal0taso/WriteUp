#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  int h, w;
  bool flg;
  string ans = "Yes";
  cin >> h >> w;
  vector<string> s(h);
  REP(i, h) { cin >> s[i]; }
  REP(i, h) {
    REP(j, w) {
      if (s[i][j] == '#') {
        flg = false;
        FOR(k, i - 1, i + 2) {
          if (k == i | k < 0 | k >= h)
            continue;
          if (s[k][j] == '#')
            flg = true;
        }
        FOR(l, j - 1, j + 2) {
          if (l == j | j < 0 | j >= w)
            continue;
          if (s[i][l] == '#')
            flg = true;
        }
        if (!flg)
          ans = "No";
      }
    }
  }

  puts(ans.c_str());
  return 0;
}

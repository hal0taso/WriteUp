#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
using namespace std;

int main() {
  int h, w, cnt;
  cin >> h >> w;
  vector<string> s(h);
  REP(i, h) { cin >> s[i]; }
  REP(i, h) {
    REP(j, w) {
      if (s[i][j] == '#')
        continue;
      cnt = 0;
      for (int si = i - 1; si <= i + 1; si++) {
        for (int sj = j - 1; sj <= j + 1; sj++) {
          if (si < 0 | si >= h | sj < 0 | sj >= w)
            continue;
          if (si == i & sj == j)
            continue;
          if (s[si][sj] == '#')
            cnt++;
        }
      }
      s[i][j] = '0' + cnt;
    }
  }
  REP(i, h) { cout << s[i] << endl; }
  return 0;
}

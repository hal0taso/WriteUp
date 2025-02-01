#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  int h, w;
  cin >> h >> w;
  string s;
  vector<string> a;
  vector<int> r(w, 0);
  REP(i, h) {
    cin >> s;
    if (s.find("#") == string::npos) {
      continue;
    }
    a.push_back(s);
    REP(j, w) {
      if (s[j] == '#')
        r[j]++;
    }
  }

  REP(i, a.size()) {
    REP(j, w) {
      if (r[j] > 0)
        cout << a[i][j];
    }
    cout << endl;
  }
  return 0;
}

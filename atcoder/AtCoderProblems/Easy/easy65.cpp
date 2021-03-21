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
  int ai = s.size(), zi = 0;
  REP(i, s.size()) {
    if (s[i] == 'A' & i < ai) {
      ai = i;
    }
    if (s[i] == 'Z') {
      zi = i;
    }
  }
  cout << zi - ai + 1 << endl;
}

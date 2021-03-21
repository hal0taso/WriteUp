#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  int a, b;
  bool flg;
  cin >> a >> b;
  FOR(i, 1, 1010) {
    flg = (a == (int)((double)i * 0.08));
    ;
    flg &= (b == (int)((double)i * 0.10));
    if (flg) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}

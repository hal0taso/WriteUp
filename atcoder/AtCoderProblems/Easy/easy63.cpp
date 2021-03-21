#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  int n, k = 1, cnt = 0, a;
  bool flg = false;
  cin >> n;
  REP(i, n) {
    cin >> a;
    if (a == k) {
      k++;
      flg = true;
    } else {
      cnt++;
    }
  }
  if (flg)
    cout << cnt << endl;
  else
    cout << -1 << endl;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  int n, m, total = 0, p, x;
  cin >> n;
  vector<int> t(n);

  REP(i, n) {
    cin >> t[i];
    total += t[i];
  }
  cin >> m;
  REP(i, m) {
    cin >> p >> x;
    cout << total - t[p - 1] + x << endl;
  }
  return 0;
}

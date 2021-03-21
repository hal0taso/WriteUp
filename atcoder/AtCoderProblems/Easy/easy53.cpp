#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
int main() {
  int n, m, a, b;
  cin >> n >> m;
  vector<int> e(n, 0);
  REP(i, m) {
    cin >> a >> b;
    e[a - 1]++;
    e[b - 1]++;
  }
  REP(i, n) { cout << e[i] << endl; }
  return 0;
}

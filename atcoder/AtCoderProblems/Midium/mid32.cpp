#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

bool comp(char a, char b) { return a > b; }

int main() {
  int n, y;
  cin >> n >> y;
  REP(i, n + 1) {
    REP(j, n - i + 1) {
      if (y == 10000 * i + 5000 * j + 1000 * (n - i - j)) {
        cout << i << ' ' << j << ' ' << n - i - j << endl;
        return 0;
      }
    }
  }
  cout << -1 << ' ' << -1 << ' ' << -1 << endl;
  return 0;
}

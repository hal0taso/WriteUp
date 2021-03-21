#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  int a, b, k;
  cin >> a >> b >> k;
  if (b - a + 1 <= 2 * k) {
    FOR(i, a, b + 1) { cout << i << endl; }
  } else {
    FOR(i, a, a + k) { cout << i << endl; }
    FOR(i, b - k + 1, b + 1) { cout << i << endl; }
  }
  return 0;
}

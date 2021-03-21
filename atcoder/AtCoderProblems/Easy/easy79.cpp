#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)

int main() {
  long long n, a, b;
  cin >> n >> a >> b;
  if ((b - a) % 2) {
    if (a - 1 < n - b) {
      a = 1 - a;
    } else {
      b = n + (n - b) + 1;
    }
  }
  cout << (b - a) / 2 << endl;
  return 0;
}

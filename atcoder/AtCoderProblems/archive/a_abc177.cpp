#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ull powmod(ull a, ull b, ull mod) {
  ull res = 1;
  for (; b; b >>= 1) {
    if (b & 1) {
      res = res * a % mod;
    }
    a = a * a % mod;
  }
  return res;
}

int main() {
  int d, t, s;
  cin >> d >> t >> s;
  if (d <= t * s) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}

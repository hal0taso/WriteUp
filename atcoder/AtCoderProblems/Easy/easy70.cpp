#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  int x;
  cin >> x;
  int a, b, c;
  a = x / 100;
  b = (x % 100) / 5;
  if (x % 5 != 0) {
    b++;
  }
  if (b <= a) {
    cout << 1 << endl;
  } else {
    cout << 0 << endl;
  }

  return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  int a, b, c;
  cin >> a >> b;
  c = a + b;
  if (c >= 15 & b >= 8) {
    cout << 1 << endl;
  } else if (c >= 10 & b >= 3) {
    cout << 2 << endl;
  } else if (c >= 3) {
    cout << 3 << endl;
  } else {
    cout << 4 << endl;
  }
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  long long a, b, c;
  cin >> a >> b >> c;
  if (c % 2 == 1) {
    if (a < b) {
      puts("<");
    } else if (a > b) {
      puts(">");
    } else {
      puts("=");
    }
  } else {
    if (max(a, -a) < max(b, -b))
      puts("<");
    else if (max(a, -a) > max(b, -b))
      puts(">");
    else
      puts("=");
  }
  return 0;
}

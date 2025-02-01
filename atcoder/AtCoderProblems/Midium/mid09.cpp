#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

long long extGCD(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long d = extGCD(b, a % b, y, x);
  y -= a / b * x;
  return d;
}

int main() {
  ll a, b, c, d;
  ll x, y;
  cin >> a >> b >> c;
  // x * a - y * b = c
  d = extGCD(a, b, x, y);
  if (c % d == 0)
    puts("YES");
  else
    puts("NO");
  return 0;
}

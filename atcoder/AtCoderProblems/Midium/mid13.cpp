#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  ll n, pt = 0, ct, diff, x, y, dist;
  cin >> n;
  pair<ll, ll> p(0, 0), c;
  REP(i, n) {
    cin >> ct >> x >> y;
    c = make_pair(x, y);
    dist = abs(c.first - p.first) + abs(c.second - p.second);
    diff = ct - pt;
    if (diff < dist | (diff - dist) % 2 == 1) {
      puts("No");
      return 0;
    }
    pt = ct;
    p = c;
  }
  puts("Yes");

  return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  ll n, a, b, ans = 0;
  cin >> n >> a >> b;
  if (a > b | (n == 1 & a != b)) {
    cout << ans << endl;
    return 0;
  }
  ans++;
  if (n != 1) {
    ans += (b - a) * (n - 2);
  }
  cout << ans << endl;

  return 0;
}

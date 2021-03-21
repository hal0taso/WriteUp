#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)

int main() {
  int n, ans = 0;
  cin >> n;
  vector<int> a(n);
  REP(i, n) {
    cin >> a[i];
    ans += a[i] - 1;
  }
  cout << ans << endl;
  return 0;
}

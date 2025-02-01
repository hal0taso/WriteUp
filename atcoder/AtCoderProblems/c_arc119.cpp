#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  REP(i, n) { cin >> a[i]; }
  map<long long, long long> m;
  long long ans = 0;
  long long C = 0;
  m[0] = 1;
  REP(i, n) {
    if (i % 2 == 0)
      C += a[i];
    else
      C -= a[i];

    ans += m[C];
    m[C]++;
  }
  cout << ans << endl;
  return 0;
}

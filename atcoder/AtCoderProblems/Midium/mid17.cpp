#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  int N;
  ull T, prev = 0, ans = 0;
  cin >> N >> T;
  vector<ull> t(N);
  REP(i, N) {
    cin >> t[i];
    if (t[i] <= prev + T) {
      ans += t[i] - prev;
    } else {
      ans += T;
    }
    prev = t[i];
  }
  ans += T;
  cout << ans << endl;
  return 0;
}

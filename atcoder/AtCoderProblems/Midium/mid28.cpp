#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  long long n, k;
  cin >> n >> k;
  vector<long long> p(n + 1, 0);
  long long ans = 0;
  FOR(i, 1, n + 1) { cin >> p[i]; }
  long long tmp = 0;
  REP(i, k) { tmp += p[i]; }
  FOR(i, 1, n - k + 2) {
    tmp -= p[i - 1];
    tmp += p[i + k - 1];
    if (ans < tmp) {
      ans = tmp;
    }
  }
  ans += k;
  if (ans % 2) {
    cout << ans / 2 << ".5" << endl;
  } else {
    cout << ans / 2 << endl;
  }
  return 0;
}

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

#define FOR(i, a, b) for (long i = a; i < b; ++i)
#define REP(i, n) for (long i = 0; i < n; ++i)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
  long n, k;

  cin >> n >> k;
  vector<long> l(k), r(k);
  vector<long> dp(n + 1);
  REP(i, k) cin >> l[i] >> r[i];
  dp[1] = 1;
  FOR(i, 2, n) {
    REP(j, k) {
      long li = i - r[i];
      long ri = i - l[i];
      if (ri < 0) {
        continue
      };
      li = max(li, i);
      dp[i] +=
    }
  }
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  ull n, tot = 0, ans;
  cin >> n;
  vector<ull> cnt(n, 0);
  vector<ull> A(n);
  vector<ull> C(n);
  REP(i, n) {
    cin >> A[i];
    cnt[A[i] - 1]++;
  }
  REP(i, n) { tot += cnt[i] * (cnt[i] - 1) / 2; }
  REP(i, n) {
    ans = tot - cnt[A[i] - 1] * (cnt[A[i] - 1] - 1) / 2 +
          (cnt[A[i] - 1] - 1) * (cnt[A[i] - 1] - 2) / 2;
    cout << ans << endl;
  }
  return 0;
}

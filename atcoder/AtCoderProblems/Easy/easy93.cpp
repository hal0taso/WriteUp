#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

#define MOD 1000000007

int main() {
  ull n, total = 0, ai, ans = 2020202020;
  cin >> n;
  vector<ull> a(n);
  REP(i, n) {
    cin >> ai;
    total += 2 * ai;
    a[i] = total;
  }
  ull h = total / 2;
  REP(i, n - 1) {
    if (a[i] > h && a[i] - h < ans) {
      ans = a[i] - h;
    } else if (a[i] < h && h - a[i] < ans) {
      ans = h - a[i];
    } else if (a[i] == h) {
      ans = 0;
    }
  }
  cout << ans << endl;

  return 0;
}

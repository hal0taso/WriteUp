#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)

int main() {
  int n, ans;
  cin >> n;
  vector<int> a(n);
  REP(i, n) { cin >> a[i]; }
  REP(i, n) {
    if (a[a[i] - 1] == i + 1)
      ans++;
  }
  cout << ans / 2 << endl;
  return 0;
}

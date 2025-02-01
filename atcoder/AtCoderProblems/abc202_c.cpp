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
  vector<int> a(n + 1);
  vector<int> b(n + 1);
  vector<int> c(n + 1);
  vector<long long> Ca(n + 1, 0);
  vector<long long> Cb(n + 1, 0);
  long long ans = 0;
  FOR(i, 1, n + 1) {
    cin >> a[i];
    Ca[a[i]]++;
  }
  FOR(i, 1, n + 1) { cin >> b[i]; }
  FOR(i, 1, n + 1) {
    cin >> c[i];
    Cb[b[c[i]]]++;
  }

  FOR(i, 1, n + 1) { ans += Ca[i] * Cb[i]; }
  cout << ans << endl;
  return 0;
}

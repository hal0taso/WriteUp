#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n + 1);
  vector<ll> accum(n + 1, 0);
  vector<ll> accum2(n + 1, 0);
  vector<ll> m(n + 1, 0);
  FOR(i, 1, n + 1) {
    cin >> a[i];
    accum[i] = a[i] + accum[i - 1];
    accum2[i] = accum[i] + accum2[i - 1];
    m[i] = max(m[i - 1], a[i]);
  }
  FOR(i, 1, n + 1) { cout << m[i] * i + accum2[i] << endl; }
  return 0;
}

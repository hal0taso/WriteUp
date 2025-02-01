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
  vector<ll> a(n);
  vector<ll> b(n);
  ll sum_a = 0;
  ll sum_b = 0;
  REP(i, n) {
    cin >> a[i];
    sum_a += a[i];
  }
  REP(i, n) {
    cin >> b[i];
    sum_b += b[i];
  }
  if (sum_a != sum_b) {
    cout << -1 << endl;
    return 0;
  }

  ll ans = 0;
  bool flg = true;
  ll max_j = 0;
  REP(i, n) {
    REP(j, n) {
      if (a[j] < 0) {
        continue;
      }
      if (a[j] >= 0 && b[i] == a[j] + j - i) {
        ans += max(i - j, j - i);
        a[j] = -1;
        if (i == j) {
          if (j < max_j)
            ans += 2;
        }
        if (j > max_j)
          max_j = j;
        break;
      }
      if (j == n - 1) {
        flg &= false;
      }
    }
  }
  if (flg)
    cout << ans / 2 << endl;
  else
    cout << -1 << endl;

  return 0;
}

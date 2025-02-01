#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)

int main() {
  long long K, A, B;
  cin >> K >> A >> B;
  long long ans = 0;
  if (K - A + 1 < 2)
    ans = K + 1;
  else if (A + 2 >= B)
    ans = K + 1;
  else {
    ans = A;
    K -= A - 1;
    if (K % 2 == 1) {
      K--;
      ans++;
    }
    ans += (B - A) * (K / 2);
  }
  cout << ans << endl;
  return 0;
}

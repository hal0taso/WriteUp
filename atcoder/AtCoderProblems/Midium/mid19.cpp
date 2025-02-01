#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  int R, G, B, N;
  ll ans = 0;
  cin >> R >> G >> B >> N;
  REP(r, 3001) {
    if (R * r > N)
      break;
    REP(g, 3001) {
      if (R * r + g * G > N)
        break;
      if ((N - R * r - g * G) % B == 0)
        ans++;
    }
  }
  cout << ans << endl;
  return 0;
}

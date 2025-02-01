#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  REP(i, H) { cin >> S[i]; }
  // vector<vector<int>> dp(H, vector<int>(W, 0));
  ll ans = 1;
  REP(k, H + W - 1) {
    int flg = 0;
    FOR(i, max(0, k - W + 1), min(k + 1, H)) {
      int j = k - i;
      if (S[i][j] == '.') {
        flg |= 1;
      } else if (S[i][j] == 'R') {
        flg |= (1 << 1);
      } else {
        flg |= (1 << 2);
      }
    }
    if (flg == 1) {
      ans *= 2;
    } else if (flg >= 6) {
      ans *= 0;
    }
    ans %= 998244353;
  }
  cout << ans << endl;
  return 0;
}

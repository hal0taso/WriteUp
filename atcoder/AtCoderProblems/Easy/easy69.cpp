#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  string s;
  cin >> s;
  int n = s.size();
  vector<vector<int>> dp(n, vector<int>(4, 0));
  REP(i, min(n, 4)) { dp[i][i] = 1; }

  REP(i, n - 1) { // i文字目
    REP(j, 4) {   // j-1文字前 (S.substr(i-j, j))
      REP(k, 4) { // k-1文字先 (S.substr(i+k, k))
        if (i + k + 1 >= n | i - j < 0) {
          continue;
        }
        // printf("i:%d, j:%d, k:%d;", i, j, k);
        // printf(" %s, %s, dp[%d+%d+1][%d]=max(%d+1, %d)",
        //        s.substr(i - j, j + 1).c_str(), s.substr(i + 1, k +
        //        1).c_str(), i, k, k, dp[i][j], dp[i + k + 1][k]);
        if (s.substr(i - j, j + 1) != s.substr(i + 1, k + 1)) {
          dp[i + k + 1][k] = max(dp[i][j] + 1, dp[i + k + 1][k]);
        }
        // printf("=%d\n", dp[i + k + 1][k]);
      }
    }
  }

  int ans = 0;
  REP(i, 4) {
    if (dp[n - 1][i] > ans)
      ans = dp[n - 1][i];
  }
  cout << ans << endl;
  return 0;
}

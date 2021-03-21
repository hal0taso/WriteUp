#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

#define MOD 1000000007

int main() {
  string s;
  cin >> s;
  int ans = 0;
  int r = 0, b = 0;
  for (auto si : s) {
    if (si == '0')
      r++;
    else
      b++;
  }
  ans = 2 * min(r, b);
  cout << ans << endl;
  return 0;
}

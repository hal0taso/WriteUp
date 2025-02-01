#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  int n, ai, ans = 0;
  cin >> n;
  map<int, int> dict;
  REP(i, n) {
    cin >> ai;
    dict[ai - 1]++;
    dict[ai]++;
    dict[ai + 1]++;
  }
  for (const auto &[key, value] : dict) {
    if (value > ans)
      ans = value;
  }
  cout << ans << endl;
  return 0;
}

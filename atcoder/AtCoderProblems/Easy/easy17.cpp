#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  int n;
  cin >> n;
  vector<double> v(n);
  REP(i, n) { cin >> v[i]; }
  sort(v.begin(), v.end());
  double ans = v[0];
  FOR(i, 1, n) { ans = (ans + v[i]) / 2; }
  cout << ans << endl;
  return 0;
}

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
  int k, n;
  cin >> k >> n;
  vector<int> x(n);
  vector<int> d(n);
  REP(i, n) { cin >> x[i]; }
  int pad = k - x[n - 1];
  REP(i, n) { x[i] += pad; }
  d[0] = x[0];
  FOR(i, 2, n) { d[i] = x[i] - x[i - 1]; }

  int max_diff = *max_element(d.begin(), d.end());
  cout << k - max_diff << endl;
  return 0;
}

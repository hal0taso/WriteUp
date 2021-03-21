#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  int n, m, num_ac = 0, num_wa = 0, pi;
  string si;
  cin >> n >> m;
  vector<int> ac(n, 0);
  vector<int> wa(n, 0);
  REP(i, m) {
    cin >> pi >> si;
    if (si == "AC" & ac[pi] == 0) {
      num_wa += wa[pi];
      num_ac++;
      ac[pi]++;
    }
    if (si == "WA")
      wa[pi]++;
  }
  cout << num_ac << " " << num_wa << endl;
  return 0;
}

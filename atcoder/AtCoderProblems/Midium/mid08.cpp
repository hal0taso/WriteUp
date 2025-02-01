#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  int n, a, lb = 0, ub;
  cin >> n;
  vector<int> c(9, 0);
  REP(i, n) {
    cin >> a;
    if (a < 400)
      c[0]++;
    else if (a < 800)
      c[1]++;
    else if (a < 1200)
      c[2]++;
    else if (a < 1600)
      c[3]++;
    else if (a < 2000)
      c[4]++;
    else if (a < 2400)
      c[5]++;
    else if (a < 2800)
      c[6]++;
    else if (a < 3200)
      c[7]++;
    else
      c[8]++;
  }
  REP(i, 8) {
    if (c[i] > 0)
      lb++;
  }
  ub = lb + c[8];
  cout << max(lb, 1) << " " << ub << endl;

  return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  int n, cnt = 0;
  cin >> n;
  vector<int> a(n);
  vector<int> p;
  REP(i, n) { cin >> a[i]; }
  int next = 1;
  p.push_back(next);
  while (next != 2) {
    next = a[p[cnt] - 1];
    if (find(p.begin(), p.end(), next) == p.end()) {
      p.push_back(next);
      cnt++;
    } else {
      cnt = -1;
      break;
    }
  }
  cout << cnt << endl;
  return 0;
}

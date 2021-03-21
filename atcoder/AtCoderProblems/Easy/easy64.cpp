#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  string o, e;
  cin >> o >> e;
  int n = o.size() + e.size();
  REP(i, n) {
    if (i % 2) {
      cout << e[i / 2];
    } else {
      cout << o[i / 2];
    }
  }
  cout << endl;
}

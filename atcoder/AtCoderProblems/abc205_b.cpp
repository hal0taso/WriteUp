#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  int n;
  cin >> n;
  vector<int> a(n + 1, 0);
  int ai;
  REP(i, n) {
    cin >> ai;
    if (a[ai] > 0) {
      cout << "No" << endl;
      return 0;
    }
    a[ai]++;
  }
  cout << "Yes" << endl;
  return 0;
}

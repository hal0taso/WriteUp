#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
int main() {
  int n, m, k, i, j, ai, cnt = 0;
  cin >> n >> m;
  vector<int> a(m, 0);
  for (i = 0; i < n; i++) {
    cin >> k;
    for (j = 0; j < k; j++) {
      cin >> ai;
      a[ai - 1]++;
    }
  }
  for (i = 0; i < m; i++) {
    if (a[i] == n) {
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}

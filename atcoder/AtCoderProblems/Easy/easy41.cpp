#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
int main() {
  int n, i, pi, m, cnt = 0;
  cin >> n;
  m = n;
  for (i = 0; i < n; i++) {
    cin >> pi;
    if (m >= pi) {
      m = pi;
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}

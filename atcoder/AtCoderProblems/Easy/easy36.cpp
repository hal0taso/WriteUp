#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
int main() {
  int n, m, li, ri, l = 1, r, i;
  cin >> n >> m;
  r = n;
  for (i = 0; i < m; i++) {
    cin >> li >> ri;
    if (li > l)
      l = li;
    if (ri < r)
      r = ri;
  }
  if (r < l)
    cout << 0 << endl;
  else
    cout << r - l + 1 << endl;
  return 0;
}

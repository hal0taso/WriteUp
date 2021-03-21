#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
int main() {
  int i, t, ans = 0, res = 10;
  for (i = 0; i < 5; i++) {
    cin >> t;
    ans += (t + 9) / 10;
    if (t % 10 < res && t % 10 > 0) {
      res = t % 10;
    }
  }
  if (res < 10)
    cout << (ans - 1) * 10 + res << endl;
  else
    cout << ans * 10 << endl;
  return 0;
}

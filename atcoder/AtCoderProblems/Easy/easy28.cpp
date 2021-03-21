#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
int main() {
  int n, ai, tmp = 0, ans = 1000000000;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> ai;
    while (!(ai & 1)) {
      tmp++;
      ai >>= 1;
    }
    if (ans > tmp)
      ans = tmp;
    tmp = 0;
  }
  cout << ans << endl;
  return 0;
}

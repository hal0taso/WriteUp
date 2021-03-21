#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
int main() {
  int n, cnt = 0, hi, i, ans = 0;
  cin >> n;
  vector<int> h(n);
  for (int i = 0; i < n; ++i) {
    cin >> hi;
    h[i] = hi;
  }
  for (i = 1; i < n; ++i) {
    cnt++;
    if (h[i] > h[i - 1])
      cnt = 0;
    if (cnt > ans)
      ans = cnt;
  }
  cout << ans << endl;

  return 0;
}

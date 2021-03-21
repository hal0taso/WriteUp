#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
int main() {
  int i, n, x = 0, ans = 0;
  string s;
  cin >> n >> s;
  for (i = 0; i < n; i++) {
    if (s[i] == 'I')
      x++;
    else
      x--;
    if (x > ans)
      ans = x;
  }
  cout << ans << endl;
  return 0;
}

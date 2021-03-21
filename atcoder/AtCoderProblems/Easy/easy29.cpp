#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
int main() {
  string s, sub;
  cin >> s;
  int l = (int)s.size(), diff, ans = 999;
  for (int i = 0; i < l - 2; i++) {
    sub = s.substr(i, 3);
    diff = abs(stoi(sub) - 753);
    if (ans > diff)
      ans = diff;
  }
  cout << ans << endl;
  return 0;
}

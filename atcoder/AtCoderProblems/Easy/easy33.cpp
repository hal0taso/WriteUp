#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
int main() {
  bool flg = true;
  string s;
  int a, b, i;
  cin >> a >> b >> s;
  for (i = 0; i < a; ++i) {
    flg &= (s[i] >= '0' && s[i] <= '9');
  }
  flg &= (s[a] == '-');
  for (i = a + 1; i < a + b + 1; ++i) {
    flg &= (s[i] >= '0' && s[i] <= '9');
  }
  if (flg)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}

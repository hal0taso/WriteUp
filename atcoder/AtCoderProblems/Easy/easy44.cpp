#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
int main() {
  string s;
  int a = 0, b = 0;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (i % 2) {
      if (s[i] == '0')
        a++;
      else
        b++;
    } else {
      if (s[i] == '0')
        b++;
      else
        a++;
    }
  }
  if (a > b)
    cout << b << endl;
  else
    cout << a << endl;
  return 0;
}

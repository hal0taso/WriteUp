#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
#define sup 1000000000000000000
int main() {
  long long a, b, c, k;
  cin >> a >> b >> c >> k;
  if (k % 2) {
    cout << b - a << endl;
  } else {
    cout << a - b << endl;
  }
  return 0;
}

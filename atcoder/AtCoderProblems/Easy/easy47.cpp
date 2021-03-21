#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
int main() {
  ull l0 = 2, l1 = 1, l2 = 3, tmp;
  int n;
  cin >> n;
  if (n == 1) {
    cout << l1 << endl;
    return 0;
  } else if (n == 2) {
    cout << l2 << endl;
    return 0;
  }

  for (int i = 3; i <= n; i++) {
    tmp = l2;
    l2 = l2 + l1;
    l0 = l1;
    l1 = tmp;
  }
  cout << l2 << endl;
  return 0;
}

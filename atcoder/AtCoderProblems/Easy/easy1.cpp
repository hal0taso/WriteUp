#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int calc_tap(int a, int b) {
  int n = 1;
  int tap = a;

  while (tap < b) {
    tap += (a - 1);
    n++;
  }
  return n;
}

int main() {
  int a;
  int b;
  cin >> a >> b;

  int res;
  if (b == 1) {
    res = 0;
  } else {
    res = calc_tap(a, b);
  }
  cout << res << endl;
}

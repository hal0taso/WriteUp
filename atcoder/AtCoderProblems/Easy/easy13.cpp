#include <iostream>
using namespace std;

int main() {
  int a, b, c;
  int x, y, z;
  cin >> a >> b >> c;
  int cnt = 0;
  if (a == b && b == c) {
    if (a % 2 == 0) {
      cnt = -1;
    } else {
      cnt = 0;
    }
  } else {
    while (a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
      x = a;
      y = b;
      z = c;
      a = (y + z) / 2;
      b = (z + x) / 2;
      c = (x + y) / 2;
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}

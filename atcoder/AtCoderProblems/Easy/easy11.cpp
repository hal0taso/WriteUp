#include <iostream>
using namespace std;

int main() {
  int n, res;
  cin >> n;
  if (0b1000000 <= n) {
    res = 64;
  } else if (0b100000 <= n) {
    res = 32;
  } else if (0b10000 <= n) {
    res = 16;
  } else if (0b1000 <= n) {
    res = 8;
  } else if (0b100 <= n) {
    res = 4;
  } else if (0b10 <= n) {
    res = 2;
  } else if (0b1 <= n) {
    res = 1;
  }
  cout << res << endl;
}

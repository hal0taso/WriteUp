#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  long long H, W;
  cin >> H >> W;
  long long C = H * W;
  if (H > 1 && W > 1) {
    if (C % 2 == 0) {
      cout << C / 2 << endl;
    } else {
      cout << (C + 1) / 2 << endl;
    }
  } else {
    cout << 1 << endl;
  }
}

#include <iostream>
using namespace std;

int main() {
  long n;
  long k;
  cin >> n >> k;

  if (n > k) {
    n %= k;
  }
  if (k - n < n) {
    cout << k - n << endl;
  } else {
    cout << n << endl;
  }
  return 0;
}

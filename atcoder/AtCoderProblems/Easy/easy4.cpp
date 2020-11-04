#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int main() {
  double N;
  cin >> N;
  double amount = N / 1.08;

  if (floor(ceil(amount) * 1.08) == N) {
    cout << (long)ceil(amount) << endl;
  } else if (floor(floor(amount) * 1.08) == N) {
    cout << (long)floor(amount) << endl;
  } else {
    cout << ":(" << endl;
  }
}

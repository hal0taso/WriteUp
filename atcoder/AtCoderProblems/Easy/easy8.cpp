#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string a, b;
  cin >> a >> b;
  int ab = stoi(a + b);
  double rt = sqrt((double)ab);
  if (abs(rt - round(rt)) > 0) {
    cout << "No";
  } else {
    cout << "Yes";
  }
}

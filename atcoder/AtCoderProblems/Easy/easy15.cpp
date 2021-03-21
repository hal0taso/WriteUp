#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> d(n);
  for (int i = 0; i < n; ++i) {
    cin >> d[i];
  }
  sort(d.begin(), d.end());
  int lb = d[n / 2 - 1];
  int ub = d[n / 2];
  cout << ub - lb << endl;
}

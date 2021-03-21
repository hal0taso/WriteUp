#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int na, nb, m;
  cin >> na >> nb >> m;
  vector<int> a(na);
  vector<int> b(nb);
  vector<int> dscnt(m);

  int ai;
  for (int i = 0; i < na; ++i) {
    cin >> ai;
    a[i] = ai;
  }

  int bi;
  for (int i = 0; i < nb; ++i) {
    cin >> bi;
    b[i] = bi;
  }

  int xi, yi, ci;
  for (int i = 0; i < m; ++i) {
    cin >> xi >> yi >> ci;
    dscnt[i] = a[xi - 1] + b[yi - 1] - ci;
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(dscnt.begin(), dscnt.end());

  if (a[0] + b[0] < dscnt[0]) {
    cout << a[0] + b[0] << endl;
  } else {
    cout << dscnt[0] << endl;
  }
  return 0;
}

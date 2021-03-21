#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  int c;
  for (int i = 0; i < n; ++i) {
    cin >> c;
    a[i] = c;
  }
  sort(a.begin(), a.end());
  int cnt;
  for (int i = 0; i < n - 1; ++i) {
    if (x >= a[i]) {
      x -= a[i];
      cnt++;
    } else {
      break;
    }
  }
  if (x == a[n - 1])
    cnt++;
  cout << cnt << endl;
  return 0;
}

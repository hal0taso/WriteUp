#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  int d, x;

  cin >> n;
  cin >> d >> x;
  int ai;
  int cnt = x;
  for (int i = 0; i < n; ++i) {
    cin >> ai;
    cnt += (d - 1) / ai + 1;
  }
  cout << cnt << endl;
  return 0;
}

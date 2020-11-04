#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  int N;
  vector<int> a(N);
  int res = 0;

  cin >> N;
  REP(i, N) { cin >> a[i]; }
  sort(a.begin(), a.end(), greater<int>());

  for (int i = 0; i < N; i += 2) {
    res += a[i];
  }
  for (int i = 1; i < N; i += 2) {
    res -= a[i];
  }
  cout << res << endl;
}

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
int main() {
  int n, i, ai;
  cin >> n;
  vector<int> a(n), tmp(n);
  for (i = 0; i < n; ++i) {
    cin >> ai;
    a[i] = ai;
    tmp[i] = ai;
  }
  sort(a.begin(), a.end());
  for (i = 0; i < n; ++i) {
    if (tmp[i] == a[n - 1])
      cout << a[n - 2] << endl;
    else
      cout << a[n - 1] << endl;
  }
  return 0;
}

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

bool comp(int n, vector<int> u, vector<int> v) {
  for (int i = 0; i < n; ++i) {
    if (u[i] != v[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  int n;
  int x;
  cin >> n;
  vector<int> p(n);
  vector<int> q(n);
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    v[i] = i + 1;
    cin >> x;
    p[i] = x;
  }
  int a = 1;
  while (!comp(n, v, p)) {
    next_permutation(v.begin(), v.end());
    a++;
  }
  for (int i = 0; i < n; ++i) {
    v[i] = i + 1;
    cin >> x;
    q[i] = x;
  }
  int b = 1;
  while (!comp(n, v, q)) {
    next_permutation(v.begin(), v.end());
    b++;
  }
  if (a >= b) {
    cout << a - b << endl;
  } else {
    cout << b - a << endl;
  }
  return 0;
}

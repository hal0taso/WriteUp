#include <iostream>
#include <set>
using namespace std;

int find_min(int x, set<int> s) {
  while (s.find(x) != s.end()) {
    x++;
  }
  return x;
}

int main() {
  int n;
  cin >> n;
  set<int> s;
  int x = 0;
  int p;
  for (int i; i < n; ++i) {
    cin >> p;
    s.insert(p);
    if (p == x) {
      x = find_min(x, s);
    }
    cout << x << endl;
  }
}

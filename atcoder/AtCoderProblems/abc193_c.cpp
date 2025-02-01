#include <iostream>
#include <set>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

long pow(long a, long b) {
  long res = 1;
  for (; b; b >>= 1) {
    if (b & 1) {
      res = res * a;
    }
    a = a * a;
  }
  return res;
}
int main() {
  long n;
  cin >> n;
  long a = 2;
  long b = 2;
  set<long> s;
  long x = pow(a, b);
  while (x <= n) {
    while (x <= n) {
      if (s.find(x) == s.end()) {
        s.insert(x);
      }
      b++;
      x = pow(a, b);
    }
    a++;
    b = 2;
    x = pow(a, b);
  }
  cout << n - s.size() << endl;
  return 0;
}

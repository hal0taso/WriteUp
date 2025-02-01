#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long ull;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  ull n;
  cin >> n;
  vector<ull> a(n);
  vector<ull> b(n);
  REP(i, n) { cin >> a[i]; }
  REP(i, n) { cin >> b[i]; }
  vector<ull> x(n);
  ull a_m = a[0];
  REP(i, n) {
    if (a[i] > a_m) {
      a_m = a[i];
    }
    x[i] = a_m * b[i];
  }
  ull c = x[0];
  REP(i, n) {
    if (x[i] > c) {
      c = x[i];
    }
    cout << c << endl;
  }
}

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

#define FOR(i, a, b) for (long i = a; i < b; ++i)
#define REP(i, n) for (long i = 0; i < n; ++i)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
  long n;
  cin >> n;
  vector<long> A(1000001, 0);
  FOR(i, 1, 1000000) {
    FOR(j, i + 1, (1000000 + i) / i) { A[i * j] += 2; }
  }
  FOR(i, 1, 1001) { A[i * i] += 1; }
  long ans = 0;
  FOR(i, 1, n) { ans += A[i]; }
  cout << ans << endl;
}

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
  long n, x, m;
  cin >> n >> x >> m;
  vector<long> a;
  a.push_back(x);
  long ans = x;
  FOR(i, 1, n) {
    long r = (a[i - 1] * a[i - 1]) % m;
    if (r == a[i - 1]) {
      ans += n - i * a[i - 1];
      break;
    } else if (r == x) {
      size_t s = a.size();
      long res = (n - i) % s;
      long c = (n - i) / s;
      ans += (c * ans);
      REP(j, s) { ans += a[j]; }
      break;
    } else if (r == 0) {
      break;
    }
    ans += r;
    a.push_back(r);
  }
  cout << ans << endl;
}

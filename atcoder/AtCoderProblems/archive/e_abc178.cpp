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
  long n;
  cin >> n;
  ll x_i, y_i;
  vector<ll> z;
  vector<ll> w;
  REP(i, n) {
    cin >> x_i >> y_i;
    z.push_back(x_i + y_i);
    w.push_back(x_i - y_i);
  }
  size_t zmax = distance(z.begin(), max_element(z.begin(), z.end()));
  size_t zmin = distance(z.begin(), min_element(z.begin(), z.end()));
  size_t wmax = distance(w.begin(), max_element(w.begin(), w.end()));
  size_t wmin = distance(w.begin(), min_element(w.begin(), w.end()));
  cout << max({z[zmax] - z[zmin], w[wmax] - w[wmin]}) << endl;
}

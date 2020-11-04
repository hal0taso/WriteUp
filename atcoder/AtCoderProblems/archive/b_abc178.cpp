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
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << max({a * c, b * d, a * d, b * c}) << endl;
}

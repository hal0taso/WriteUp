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
  int in;
  int x, y, z;
  int c_x = 0;
  int c_y = 0;
  int c_z = 0;
  int c_zero = 0;
  int n;
  x = 0;
  y = 0;
  z = 0;
  cin >> n;
  REP(i, n) {
    cin >> in;
    if (in == 0) {
      ++c_zero;
    } else {
      if (x == 0 | x == in) {
        x = in;
        c_x++;
      } else if (y == 0 | y == in) {
        y = in;
        c_y++;
      } else if (z == 0 | z == in) {
        z = in;
        c_z++;
      } else {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  if (x == 0 && y == 0 && z == 0) {
    cout << "Yes" << endl;
  } else if (3 * c_x == 2 * n && 3 * c_zero == n) {
    cout << "Yes" << endl;
  } else if (3 * c_x == n && 3 * c_y == n && 3 * c_z == n && x ^ y ^ z == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}

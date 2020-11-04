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
  int n;
  cin >> n;
  int a, b;
  int counter = 0;
  bool flag = false;
  REP(i, n) {
    cin >> a >> b;
    if (a == b) {
      counter++;
    } else {
      counter = 0;
    }
    if (counter > 2) {
      flag = true;
    }
  }
  if (flag == true) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}

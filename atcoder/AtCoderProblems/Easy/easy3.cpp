#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  string s;
  cin >> s;

  ll rank = 0;
  ll ovs = 0;

  REP(i, n) {
    if (rank < a + b) {
      if (s[i] == 'a') {
        ++rank;
        cout << "Yes" << endl;
      } else if (s[i] == 'b' && ovs < b) {
        ++rank;
        ++ovs;
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    } else {
      cout << "No" << endl;
    }
  }
}

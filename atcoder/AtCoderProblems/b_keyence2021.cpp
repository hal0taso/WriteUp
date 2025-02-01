#include <iostream>
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
  vector<int> cnt(2000001, 0);
  int pi;
  int x = 0;
  REP(i, n) {
    cin >> pi;
    cnt[pi]++;
    while (cnt[x] > 0) {
      x++;
    }
    cout << x << endl;
  }
}

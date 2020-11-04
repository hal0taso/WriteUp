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

const ll MOD = 1000000007;

int main() {
  ll s;
  cin >> s;
  vector<ll> A;
  A.push_back(0);
  A.push_back(0);
  A.push_back(0);
  A.push_back(1);
  if (s < 4) {
    cout << A[s] << endl;
  } else {
    FOR(i, 4, s + 1) { A.push_back((A[i - 3] + A[i - 1]) % MOD); }
    cout << A[s] << endl;
  }
  return 0;
}

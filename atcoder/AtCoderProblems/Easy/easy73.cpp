#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int count(string s) {
  int ret = 0;
  for (auto si : s) {
    ret += si - '0';
  }
  return ret;
}

int main() {
  string N;
  cin >> N;

  int ans = count(N), tmp;
  for (int i = 0; i < N.size(); i++) {
    tmp = count(N.substr(0, i));
    tmp += (N[i] - '0') - 1;
    tmp += 9 * (N.size() - i - 1);

    if (ans < tmp)
      ans = tmp;
  }
  cout << ans << endl;
  return 0;
}

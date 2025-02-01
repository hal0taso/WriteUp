#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  long long n;
  cin >> n;
  vector<char> ans;
  if (n & 1)
    ans.push_back('A');

  n = n >> 1;
  while (n > 0) {
    ans.push_back('B');
    if (n & 1)
      ans.push_back('A');
    n = n >> 1;
  }
  for (int i = 1; i <= ans.size(); i++) {
    cout << ans[ans.size() - i];
  }
  cout << endl;

  return 0;
}

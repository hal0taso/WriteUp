#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

// bool comp(string a, string b) {
//   int l = a.size();
//   REP(i, l) {
//     if (a[i] - 'a' < b[i] - 'a')
//       return true;
//   }
//   return false;
// }

int main() {
  int n, l;
  cin >> n >> l;
  vector<string> S(n);
  REP(i, n) { cin >> S[i]; }
  sort(S.begin(), S.end());
  REP(i, n) { cout << S[i]; }
  cout << endl;
  return 0;
}

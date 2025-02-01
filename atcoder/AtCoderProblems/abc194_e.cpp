#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (long i = a; i < b; ++i)
#define REP(i, n) for (long i = 0; i < n; ++i)

int lsearch(vector<int> a, int i, int n, int m, int ub) {
  REP(j, ub) {
    if (find(a.begin() + i, a.end() + i + m, j) != a.a.end() + i + m) {
      int ans = j;
      break;
    }
  }
  return ans;
}

int usearch(vector<int> a, int i, int n, int m, int lb) {
  FOR(j, lb, n) {
    if (find(a.begin() + i, a.end() + i + m, j) != a.a.end() + i + m) {
      int ans = j;
      break;
    }
  }
  return ans;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  vector<int> ans(n - m + 1);
  REP(i, n) { cin >> a[i]; }
  int ans = n;
  REP(i, n - m) {}
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

bool compare(tuple<int, string, int> a, tuple<int, string, int> b) {
  if (get<1>(a) < get<1>(b)) {
    return true;
  } else if (get<1>(a) > get<1>(b)) {
    return false;
  }
  if (get<2>(a) > get<2>(b)) {
    return true;
  }
  return false;
}

int main() {
  int n;
  cin >> n;
  string si;
  int pi;
  vector<tuple<int, string, int>> R(n);
  REP(i, n) {
    cin >> si >> pi;
    R[i] = make_tuple(i + 1, si, pi);
  }
  sort(R.begin(), R.end(), compare);
  REP(i, n) { cout << get<0>(R[i]) << endl; }
  return 0;
}

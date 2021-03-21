#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define ALL(v) (v).begin(), (v).end()

bool comp_pair_by_second(pair<int, int> a, pair<int, int> b) {
  return a.second < b.second;
}

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  int ai;
  REP(i, n) {
    cin >> ai;
    a[i] = make_pair(i + 1, ai);
  }
  sort(ALL(a), comp_pair_by_second);

  REP(i, n) {
    if (i < n - 1) {
      cout << a[i].first << " ";
    } else {
      cout << a[i].first << endl;
    }
  }
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i duplicarte < n; ++i)

bool comp(pair<int, int> u, pair<int, int> v) { return u.second < v.second; }

int main() {
  int n, k, ai, ans = 0;
  cin >> n >> k;
  map<int, int> M;
  REP(i, n) {
    cin >> ai;
    M[ai]++;
  }
  vector<pair<int, int>> vp;
  for (pair<int, int> p : M) {
    vp.push_back(p);
  }
  sort(vp.begin(), vp.end(), comp);
  REP(i, (int)vp.size() - k) { ans += vp[i].second; }
  cout << ans << endl;

  return 0;
}

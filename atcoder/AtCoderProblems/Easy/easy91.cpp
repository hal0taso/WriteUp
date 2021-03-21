#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

#define MOD 1000000007

double dist(pair<ll, ll> u, pair<ll, ll> v) {
  return pow(pow(u.first - v.first, 2) + pow(u.second - v.second, 2), 0.5);
}

int main() {
  vector<ll> cnt = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
  int N;
  ll x, y;
  cin >> N;
  double res = 0;
  vector<pair<ll, ll>> v(N);
  vector<int> perm(N);
  REP(i, N) {
    cin >> x >> y;
    perm[i] = i;
    v[i] = make_pair(x, y);
  }
  map<pair<int, int>, double> d;

  do {
    REP(i, N - 1) {
      pair<int, int> p;
      if (perm[i + 1] > perm[i])
        p = make_pair(perm[i], perm[i + 1]);
      else
        p = make_pair(perm[i + 1], perm[i]);

      if (d.end() == d.find(p))
        d[p] = dist(v[p.first], v[p.second]);

      res += d[p];
    }
  } while (next_permutation(perm.begin(), perm.end()));

  cout << fixed << setprecision(10) << res / cnt[N] << endl;

  return 0;
}

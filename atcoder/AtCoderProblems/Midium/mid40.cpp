#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main()
{
  int N, M;
  cin >> N >> M;
  vector<int> X(M);
  REP(i, M) { cin >> X[i]; }
  vector<int> diff(M - 1);
  sort(X.begin(), X.end());
  REP(i, M - 1) { diff[i] = X[i + 1] - X[i]; }
  sort(diff.begin(), diff.end());

  int ans = X[M - 1] - X[0];
  if (N >= M)
  {
    ans = 0;
  }
  else
  {
    FOR(i, 1, N) { ans -= diff[M - 1 - i]; }
  }
  cout << ans << endl;
  return 0;
}

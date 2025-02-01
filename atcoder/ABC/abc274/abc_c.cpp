#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main()
{
  int N;
  cin >> N;
  vector<int> A(N + 1);
  vector<int> ans(2 * (N + 1), 0);
  FOR(i, 1, N + 1)
  {
    cin >> A[i];
    A[i];
  }
  FOR(i, 1, N + 1)
  {
    int j = A[i];
    ans[2 * i] = ans[j] + 1;
    ans[2 * i + 1] = ans[j] + 1;
  }
  FOR(i, 1, 2 * N + 2)
  {
    cout << ans[i] << endl;
  }

  return 0;
}

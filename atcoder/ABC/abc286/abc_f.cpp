#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main()
{
  int M = 110;
  vector<int> A(M);
  A[0] = 110;
  FOR(i, 1, M)
  {
    A[i] = i;
  }
  cout << M << '\n'
       << flush;
  REP(i, M)
  {
    cout << A[i];
    if (i < M - 1)
      cout << ' ';
    else
      cout << '\n'
           << flush;
  }
  vector<int> B(M);
  int ans;
  REP(i, M)
  {
    cin >> B[i];
    if (B[i] == 1)
      ans = i;
  }
  cout << ans << '\n'
       << flush;

  return 0;
}

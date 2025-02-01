#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main(void)
{
  int n;
  cin >> n;
  vector<long long> A(n);
  vector<long long> acc(n + 1, 0);
  REP(i, n)
  {
    cin >> A[i];
  }
  vector<long long> B(n + 1, 0);
  FOR(i, 1, n + 1)
  {
    B[i] = B[i - 1];
  }

  return 0;
}
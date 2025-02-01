#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> A(m);
  REP(i, m)
  {
    cin >> A[i];
  }
  vector<int> B(n + 1);
  iota(B.begin(), B.end(), 0);
  for (int i : A)
  {
    swap(B[i], B[i + 1]);
  }
  vector<int> pos(n + 1);
  FOR(i, 1, n + 1)
  {
    pos[B[i]] = i;
  }

  iota(B.begin(), B.end(), 0);
  for (int i : A)
  {
    if (B[i] == 1)
    {
      cout << pos[B[i + 1]] << '\n';
    }
    else if (B[i + 1] == 1)
    {
      cout << pos[B[i]] << '\n';
    }
    else
    {
      cout << pos[1] << '\n';
    }
    swap(B[i], B[i + 1]);
  }

  // cout << "YES" << endl;
  return 0;
}

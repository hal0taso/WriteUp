#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  REP(i, n)
  {
    cin >> a[i];
  }
  int q;
  cin >> q;
  int op;
  int k, x;
  REP(i, q)
  {
    cin >> op;
    if (op == 1)
    {
      cin >> k >> x;
      k--;
      a[k] = x;
    }
    else
    {
      cin >> k;
      k--;
      cout << a[k] << endl;
    }
  }
  return 0;
}
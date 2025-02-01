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
  int q;
  cin >> q;
  vector<int> a(n, 0);
  REP(i, q)
  {
    int op;
    int x;
    cin >> op >> x;
    x--;
    if (op == 1)
    {
      a[x]++;
    }
    else if (op == 2)
    {
      a[x] += 2;
    }
    else
    {
      if (a[x] >= 2)
      {
        puts("Yes");
      }
      else
        puts("No");
    }
  }
  return 0;
}

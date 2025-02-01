#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main()
{
  int t;
  cin >> t;
  REP(i, t)
  {
    int n;
    cin >> n;
    int a;
    int cnt = 0;
    REP(j, n)
    {
      cin >> a;
      if (a % 2 == 1)
        cnt++;
    }
    cout << cnt << endl;
  }
  return 0;
}
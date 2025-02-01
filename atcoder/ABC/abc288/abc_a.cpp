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
  vector<pair<int, int>> v(n);
  REP(i, n)
  {
    int a, b;
    cin >> a >> b;
    cout << a + b << '\n';
  }

  return 0;
}

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
  vector<int> h(n);
  int tmp = 0;
  int ans = -1;
  REP(i, n)
  {
    cin >> h[i];
    if (h[i] > tmp)
    {
      tmp = h[i];
      ans = i + 1;
    }
  }
  std::cout << ans << endl;

  // cout << "YES" << endl;
  return 0;
}

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
  vector<string> s(n);
  REP(i, n)
  {
    cin >> s[i];
  }
  reverse(s.begin(), s.end());
  REP(i, n)
  {
    cout << s[i] << endl;
  }
  return 0;
}

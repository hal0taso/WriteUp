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
  int ans = 0;
  cin >> n;
  REP(i, n)
  {
    string s;
    cin >> s;
    if (s == "For")
      ans++;
  }
  if (ans * 2 >= n)
  {
    puts("Yes");
  }
  else
    puts("No");
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main()
{
  int a, b;
  cin >> a >> b;
  if (a > b)
  {
    swap(a, b);
  }
  if (b == a * 2 || b == a * 2 + 1)
    puts("Yes");
  else
    puts("No");
  return 0;
}

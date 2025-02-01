#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main()
{
  string s;
  cin >> s;
  for (char c : s)
  {
    char ch;
    ch = toupper(c);
    cout << ch;
  }
  cout << '\n';
  return 0;
}

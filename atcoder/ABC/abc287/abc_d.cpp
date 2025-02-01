#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main()
{
  string s, t;
  cin >> s >> t;
  int n = t.size();
  int m = s.size();
  vector<bool> head(n + 1, false); // 先頭x文字一致するか
  vector<bool> tail(n + 1, false); // 末尾x文字目一致するか
  head[0] = true;
  tail[0] = true;

  FOR(x, 1, n + 1)
  {
    head[x] = head[x - 1] && (s[x - 1] == t[x - 1] || s[x - 1] == '?' || t[x - 1] == '?');
    if (head[x] == false)
      break;
  }
  for (int x = 1; x <= n; x++)
  {
    tail[x] = tail[x - 1] && (s[m - x] == t[n - x] || s[m - x] == '?' || t[n - x] == '?');
    if (tail[x] == false)
      break;
  }
  REP(x, n + 1)
  {
    if (head[x] && tail[n - x])
      puts("Yes");
    else
      puts("No");
  }
  return 0;
}

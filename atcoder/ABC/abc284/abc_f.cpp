#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

vector<ll> z_algorithm(string S)
{
  vector<ll> A(S.size());
  A[0] = S.size();
  ll i = 1, j = 0;
  while (i < S.size())
  {
    while (i + j < S.size() && S[j] == S[i + j])
      ++j;
    A[i] = j;
    if (j == 0)
    {
      ++i;
      continue;
    }
    ll k = 1;
    while (i + k < S.size() && k + A[k] < j)
      A[i + k] = A[k], ++k;
    i += k;
    j -= k;
  }
  return A;
}

int main()
{
  int n;
  cin >> n;
  string t;
  cin >> t;
  string a = t.substr(0, n), b = t.substr(n, n);
  reverse(b.begin(), b.end());
  string x = a + b, y = b + a;
  vector<ll> zx = z_algorithm(x);
  zx.push_back(0);
  vector<ll> zy = z_algorithm(y);
  zy.push_back(0);

  for (int i = 0; i <= n; i++)
  {

    if (zx[2 * n - i] == i && zy[n + i] == n - i)
    {
      string s = y.substr(0, n - i);
      reverse(s.begin(), s.end());
      cout << x.substr(0, i) + s << endl;
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}

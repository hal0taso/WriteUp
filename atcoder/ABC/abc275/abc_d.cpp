#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

map<ll, ll> m;
ll f(ll k)
{
  ll ret = 0;
  if (k == 0)
  {
    return 1;
  }
  if (m.find(k / 2) != m.end())
    ret += m[k / 2];
  else
    ret += f(k / 2);
  if (m.find(k / 3) != m.end())
    ret += m[k / 3];
  else
    ret += f(k / 3);
  m[k] = ret;
  return ret;
}

int main()
{
  ll N;
  cin >> N;
  cout << f(N) << endl;

  return 0;
}

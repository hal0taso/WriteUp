#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main()
{
  int n, m, k;
  cin >> n >> m >> k;
  vector<ll> a(n);
  vector<ll> tmp(m);
  ll ans = 0;
  multiset<ll> s;
  multiset<ll> o;
  REP(i, n)
  {
    cin >> a[i];
    if (i < m)
    {
      tmp[i] = a[i];
    }
  }

  sort(tmp.begin(), tmp.end());
  REP(i, m)
  {
    if (i < k)
    {
      ans += tmp[i];
      s.insert(tmp[i]);
    }
    else
    {
      o.insert(tmp[i]);
    }
  }
  cout << ans;
  int head = 0;
  int tail = m;

  while (tail < n)
  {
    ll add = a[tail];
    ll drop = a[head];
    if (m != k)
    {
      // cout << '\n'
      //      << "add : " << add << endl;
      // cout << "drop: "
      //      << drop
      //      << endl;
      // cout << "*s.rbegin(): " << *s.rbegin() << endl;
      // cout << "*o.begin(): " << *o.begin() << endl;

      o.insert(add);

      if (*s.rbegin() >= drop)
      {
        ans -= drop;
        ans += *o.begin();
        s.erase(s.find(drop));
        s.insert(*o.begin());
        o.erase(o.begin());
      }
      else
      {
        o.erase(o.find(drop));
      }
      // cout << "*s.rbegin(): " << *s.rbegin() << endl;
      // cout << "*o.begin(): " << *o.begin() << endl;
      ll in, out;
      in = *o.begin();
      out = *s.rbegin();
      if (out > in)
      {
        ans -= out;
        ans += in;
        o.insert(out);
        s.insert(in);
        s.erase(s.find(out));
        o.erase(o.find(in));
      }
    }
    else
    {
      ans += add;
      ans -= drop;
    }

    cout << ' ' << ans;
    tail++;
    head++;
  }
  cout << endl;

  // cout << "YES" << endl;
  return 0;
}

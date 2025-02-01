#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)
#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)
using vvll = vector<vector<ll>>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vvd = vector<vector<double>>;
using vd = vector<double>;
using vvvb = vector<vector<vector<bool>>>;
using vvb = vector<vector<bool>>;
using vb = vector<bool>;
constexpr ll INF = 1000000000LL;

void print(vll v)
{
  for (auto vi : v)
  {
    cout << vi << ' ';
  }
  cout << '\n';
}

void print(vector<pair<ll, ll>> v)
{
  for (auto vi : v)
  {
    cout << vi.first << ' ';
  }
  cout << '\n';
  for (auto vi : v)
  {
    cout << vi.second << ' ';
  }
  cout << '\n';
}

long long gcd(long long a, long long b)
{
  if (a < b)
  {
    swap(a, b);
  }
  if (b == 0)
  {
    return a;
  }
  else
  {
    return gcd(b, a % b);
  }
}

// 12345678911 10987654321
int main()
{
  ll a, b;
  cin >> a >> b;
  if (a < b)
    swap(a, b);

  ll ans = 0;
  // if (diff != 0)
  // {
  //   ans += b / diff;
  //   ll tmp = b % diff;
  //   ll g = gcd(tmp, diff);
  //   ans += (b % diff) / g;
  // }
  // else
  //   ans = b / g;
  // cout << ans << endl;
  // ans = 0;

  // cout << gcd(a, b) << endl;
  // print(rem);

  while (a >= 1 && b >= 1)
  {
    if (a == b)
    {
      ans++;
      break;
    }
    ll g = gcd(a, b);
    // cout << "a: " << a << '\n';
    // cout << "b: " << b << '\n';
    // cout << "g: " << g << '\n';
    // cout << "d: " << a - b << '\n';

    if (g == 1)
    {
      ll diff = a - b;
      vector<ll> rem;
      for (ll k = 2; k * k <= diff; k++)
      {
        if (diff % k == 0)
          rem.push_back(k);
        while (diff % k == 0)
          diff /= k;
      }
      if (diff > 1)
        rem.push_back(diff);

      ll t = b;
      for (ll k : rem)
      {
        t = min(t, b % k);
      }
      // cout << "t: " << t << '\n';
      ans += t;
      a -= t;
      b -= t;
    }
    else
    {
      a = a / g;
      b = b / g;
      a--;
      b--;
      ans++;
    }
    // if (g == diff)
    // {
    //   ans += b /= g;
    //   break;
    // }
  }
  // ll ans = 0;
  // gcd(a, b);
  // ans += cnt;
  cout << ans << endl;
  return 0;
}

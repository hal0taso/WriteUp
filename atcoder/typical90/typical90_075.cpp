#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
// using namespace atcoder;
// using mint = modint1000000007;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)
#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)
using vvi = vector<vector<int>>;
using vi = vector<int>;
int main()
{
    ll n;
    cin >> n;
    // ll tmp = n;
    ll cnt = 0;
    for (ll p = 2; p * p <= n; p++)
    {
        while (n % p == 0)
        {
            n /= p;
            cnt++;
        }
    }
    if (n != 1)
        cnt++;
    // cout << cnt << '\n';
    ll i = 0;
    while ((1LL << i) < cnt)
    {
        i++;
    }
    cout << i << endl;

    return 0;
}
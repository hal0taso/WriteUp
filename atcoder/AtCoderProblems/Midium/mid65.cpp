#include <bits/stdc++.h>
#include <atcoder/modint>

using namespace std;
using namespace atcoder;

using mint = modint998244353;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)
#define RFOR(i, a, b) for (ll i = b - 1; i >= a; i--)
#define RREP(i, n) for (ll i = n - 1; i >= 0; i--)
#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vvll = vector<vector<ll>>;
using vll = vector<ll>;
constexpr long long INF = 20000000;

// constexpr int MOD = 1000000000 + 7;

int main()
{
    /*
    6 3
    abcdef
    abc

    L = 6
    abcdef
    a*b*c*
    L = 12
    a*b*c*d*e*f*
    a***b***c***
    L = 18
    a**b**c**d**e**f**
    a*****b*****c*****
    */

    /*
     3 2
     acp
     ae

     L=6
     a*c*p*
     a**e**
     L=12
     a***c***p***
     a*****e*****

     */

    /*
     15 9
     dnsusrayukuaiia
     dujrunuma

     L=45
     d**n**s**u**s**r**a**y**u**k**u**a**i**i**a**
     d****u****j****r****u****n****u****m****a****
    */
    ll n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    long long l = lcm(n, m);
    long long g = gcd(n, m);
    long long ans = l;
    // cerr << l << '\n';
    // cerr << g << '\n';
    if (s[0] != t[0])
        ans = -1;
    if (n == 1 || m == 1 || g > 1)
    {
        ll i = 0, j = 0;
        while (i < n && j < m)
        {
            if (s[i] != t[j])
                ans = -1;
            i += n / g;
            j += m / g;
        }
    }
    cout << ans << '\n';
    return 0;
}

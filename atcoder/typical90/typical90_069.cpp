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

constexpr ll mod = 1000000007;

long long modpow(long long a, long long n, long long mod)
{
    long long res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
int main()
{
    ll n, k;
    cin >> n >> k;
    ll ans = 1;
    if (n <= 5)
    {
        REP(i, n)
        ans = (ans * (k - i) % mod);
    }
    else
    {
        if (k < 5)
            ans = 0;
        else
        {
            REP(i, 3)
            ans = (ans * (k - i) % mod);
            ans *= modpow(k - 2, n - 3, mod);
            ans %= mod;
        }
    }
    cout << ans << '\n';
}
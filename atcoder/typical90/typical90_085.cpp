#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;

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

int main()
{
    ll k;
    cin >> k;
    ll ans = 0;
    set<tuple<ll, ll, ll>> s;
    for (ll a = 1; a * a <= k; a++)
    {
        if (k % a == 0)
        {
            ll bc = k / a;
            for (ll b = a; b * b <= bc; b++)
            {
                if (bc % b == 0)
                {
                    if (bc / b >= b)
                    {
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
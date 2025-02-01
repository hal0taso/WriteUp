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
using vvll = vector<vector<ll>>;
using vll = vector<ll>;
constexpr long long INF = (1LL << 60);
#define bit(n, k) ((n >> k) & 1)

template <typename T>
void debug(vector<T> v)
{
#ifdef ONLINE_JUDGE
#else
#endif
#ifdef LOCAL_DEBUG
    for (auto vi : v)
    {
        cerr << vi << ' ';
    }
    cout << '\n';
#endif
}

int main()
{
    long long n;
    cin >> n;
    long long w, s, v;
    long long maxs = 0;
    vector<tuple<long long, long long, long long, long long>> vec;
    for (int i = 0; i < n; i++)
    {

        cin >> w >> s >> v;
        vec.emplace_back(w + s, w, s, v);
        maxs = max(s, maxs);
    }
    sort(all(vec));
    // reverse(all(vec));
    vector dp(n + 1, vector<long long>(2 * maxs + 1, 0));

    // REP(i, maxs + 1)
    // if (i - get<1>(vec[0]) >= 0)
    //     dp[1][i] = get<3>(vec[0]);

    FOR(i, 1, n + 1)
    {
        auto [_, w, s, v] = vec[i - 1];
        cerr << "DEBUG: " << w << ", " << s << ", " << v << '\n';
        FOR(j, 1, 2 * maxs + 1)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - w >= 0 && j - w <= s)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w] + v);
        }
        debug(dp[i]);
    }
    long long ans = 0;
    REP(s, 2 * maxs + 1)
    ans = max(ans, dp[n][s]);
    cout << ans << '\n';

    return 0;
}
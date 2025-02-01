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
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> cnt(n, 0);
    REP(i, m)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        cnt[max(u, v)]++;
    }
    int ans = 0;
    REP(i, n)
    {
        if (cnt[i] == 1)
            ans++;
    }
    cout << ans << '\n';

    return 0;
}
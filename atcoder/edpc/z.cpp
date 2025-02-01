#include <bits/stdc++.h>
#include <functional>
using namespace std;

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

using Graph = vector<vector<int>>;

template <typename T, typename Compare = less<T>>
vector<pair<int, T>> monotone_minima(int H, int W, const function<T(int, int)> &f, const Compare &comp = Compare())
{
    vector<pair<int, T>> dp(H);
    function<void(int, int, int, int)> dfs = [&](int top, int bottom, int left, int right)
    {
        if (top > bottom)
            return;
        int line = (top + bottom) / 2;
        T ma;
        int mi = -1;
        for (int i = left; i <= right; i++)
        {
            T cst = f(line, i);
            if (mi == -1 || comp(cst, ma))
            {
                ma = cst;
                mi = i;
            }
        }
        dp[line] = make_pair(mi, ma);
        dfs(top, line - 1, left, mi);
        dfs(line + 1, bottom, mi, right);
    };
    dfs(0, H - 1, 0, W - 1);
    return dp;
}

template <typename T, typename Compare = less<T>>
vector<T> online_offline_dp(int W, const function<T(int, int)> &f, const Compare &comp = Compare())
{
    vector<T> dp(W + 1);
    vector<int> isset(W + 1);
    int y_base = -1, x_base = -1;
    function<T(int, int)> get_cost = [&](int y, int x) { // return dp[0, x+x_base)+f[x+x_base, y+y_base)
        return dp[x + x_base] + f(x + x_base, y + y_base);
    };
    function<void(int, int, int)> induce = [&](int l, int m, int r) { // dp[l, m) -> dp[m, r)
        x_base = l, y_base = m;
        auto ret = monotone_minima(r - m, m - l, get_cost, comp);
        for (int i = 0; i < ret.size(); i++)
        {
            if (!isset[m + i] || comp(ret[i].second, dp[m + i]))
            {
                isset[m + i] = true;
                dp[m + i] = ret[i].second;
            }
        }
    };
    function<void(int, int)> dfs = [&](int l, int r)
    {
        if (l + 1 == r)
        {
            x_base = l, y_base = l;
            T cst = l ? get_cost(0, -1) : 0;
            if (!isset[l] || comp(cst, dp[l]))
            {
                isset[l] = true;
                dp[l] = cst;
            }
        }
        else
        {
            int mid = (l + r) / 2;
            dfs(l, mid);
            induce(l, mid, r);
            dfs(mid, r);
        }
    };
    dfs(0, W + 1);
    return dp;
};

int main()
{
    int n;
    cin >> n;
    long long c;
    cin >> c;
    vector<long long> h(n, 0);
    REP(i, n)
    cin >> h[i];
    function<int64_t(int, int)> dist = [&](int i, int j)
    {
        assert(0 <= i && i < j && j <= n);
        int s = (h[i] - h[j]);
        return 1LL * s * s + 1LL * c;
    };

    cout << online_offline_dp(n - 1, dist).back() << '\n';
    return 0;
}
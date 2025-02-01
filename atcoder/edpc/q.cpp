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

constexpr int MOD = 1000000000 + 7;

struct SegmentTree
{
    vector<ll> node;
    int n;
    ll inf = 0;

    SegmentTree(int _n)
    {
        n = 1;
        while (n < _n)
            n <<= 1;
        node.assign(2 * n, inf);
    }

    void build(vector<ll> array)
    {
        for (size_t i = 0; i < array.size(); i++)
        {
            node[i + n] = array[i];
        }
        for (size_t i = n - 1; i >= 0; i--)
        {
            size_t l = i << 1 | 0;
            size_t r = i << 1 | 1;
            node[i] = max(node[l], node[r]);
        }
    }

    void update(int i, ll v)
    {
        int j = n + i;
        node[j] = v;
        while (j > 1)
        {
            j >>= 1;
            size_t l = j << 1 | 0;
            size_t r = j << 1 | 1;
            node[j] = max(node[l], node[r]);
        }
    }

    ll fold(int l, int r)
    {
        l += n;
        r += n;
        ll v = inf;
        while (l < r)
        {
            if ((l & 1) == 1)
            {
                v = max(v, node[l]);
                l++;
            }
            if ((r & 1) == 1)
            {
                r--;
                v = max(v, node[r]);
            }
            l >>= 1;
            r >>= 1;
        }
        return v;
    }
};

int main()
{
    ll n;
    cin >> n;
    vector<ll> h(n + 1, 0), a(n + 1, 0);
    ll N = 0;
    FOR(i, 1, n + 1)
    {
        cin >> h[i];
        N = max(N, h[i]);
    }
    FOR(i, 1, n + 1)
    cin >> a[i];
    // iまで見たときにj以下のもののうち最大値を調べる
    SegmentTree ST(N + 1);
    FOR(i, 1, n + 1)
    {
        // if (ST.fold(0, h[i]))
        ST.update(h[i], ST.fold(0, h[i]) + a[i]);
    }
    cout << ST.fold(0, N + 1) << '\n';
    return 0;
}
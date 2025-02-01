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

void print(vector<pair<int, int>> v)
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
struct SegTree
{
    int n;
    vector<pair<ll, ll>> dat;
    pair<ll, ll> INF = {0, 0};
    SegTree(int _n)
    {
        n = 1;
        while (n < _n)
            n *= 2;
        dat.assign(2 * n - 1, INF);
        // print(dat);
    }

    void update(int x, const pair<ll, ll> &val)
    {
        x += n - 1;
        dat[x] = val;
        while (x > 0)
        {
            x = (x - 1) / 2;
            ll sign = -1;
            if (dat[2 * x + 1].second % 2 == 0)
                sign = 1;
            dat[x] = {dat[2 * x + 1].first + sign * dat[2 * x + 2].first,
                      dat[2 * x + 1].second + dat[2 * x + 2].second};
        }
    }

    pair<ll, ll> _query(int a, int b, int k, int l, int r)
    {
        if (r <= a || b <= l)
            return INF;
        if (a <= l && r <= b)
            return dat[k];

        pair<ll, ll> vl = _query(a, b, 2 * k + 1, l, (l + r) / 2);
        pair<ll, ll> vr = _query(a, b, 2 * k + 2, (l + r) / 2, r);
        ll sign = -1;
        if (vl.second % 2 == 0)
            sign = 1;
        return {vl.first + sign * vr.first,
                vl.second + vr.second};
    }

    pair<ll, ll> query(int a, int b) { return _query(a, b, 0, 0, n); }
};

int main()
{
    int n, q;
    cin >> n >> q;
    SegTree st(n);

    REP(i, q)
    {
        int t, x, y, v;
        cin >> t >> x >> y >> v;
        x--;
        y--;
        // cout << t << ',' << x << ',' << y << ',' << v << '\n';
        if (t == 0)
        {
            st.update(x, {v, 1});
        }
        else
        {
            auto [alt, len] = st.query(min(x, y), max(x, y));
            if (len != max(x, y) - min(x, y))
                puts("Ambiguous");
            else
            {
                ll ans = 0;
                if (len % 2 == 1)
                    // alt = a_x + a_y
                    ans = alt - v;
                else
                {
                    if (x < y)
                        // alt = a_x - a_y
                        ans = -alt + v;
                    else
                    {
                        // alt = a_y - a_x
                        ans = alt + v;
                    }
                }
                cout << ans << '\n';
            }
        }
    }
    return 0;
}
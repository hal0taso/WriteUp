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
constexpr int INF = (1 << 30);
void debug_out()
{
    cerr << endl;
}

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
    cerr << H << " ";
    debug_out(T...);
}

#define debug(...) debug_out(__VA_ARGS__)
constexpr int MOD = 1000000000 + 7;

auto isin(set<pair<int, int>> &st, int x)
{
    auto itr = st.lower_bound(make_pair(x + 1, x + 1));
    itr--;
    // debug("isin", x, itr->first, itr->second);
    if ((itr->first <= x) && (x <= itr->second))
        return itr;
    return st.end();
}

void add(set<pair<int, int>> &st, int x)
{
    if (isin(st, x) != st.end())
    {
        // debug("skip");
        return;
    }
    int l1 = -INF, r1 = -INF, l2 = INF, r2 = INF;
    if (isin(st, x - 1) != st.end())
    {
        auto itr = isin(st, x - 1);
        l1 = itr->first, r1 = itr->second;
    }
    if (isin(st, x + 1) != st.end())
    {
        auto itr = isin(st, x + 1);
        l2 = itr->first, r2 = itr->second;
    }
    // debug("add", l1, r1, l2, r2);
    if (r1 > -INF && l2 < INF)
    {
        st.erase({l1, r1});
        st.erase({l2, r2});
        st.insert({l1, r2});
    }
    else if (r1 > -INF)
    {
        st.erase({l1, r1});
        st.insert({l1, x});
    }
    else if (l2 < INF)
    {
        st.erase({l2, r2});
        st.insert({x, r2});
    }
    else
    {
        st.insert({x, x});
    }
}

void remove(set<pair<int, int>> &st, int x)
{
    if (isin(st, x) == st.end())
        return;
    auto itr = isin(st, x);
    int l = itr->first, r = itr->second;
    st.erase(*itr);
    if (l < x)
        st.insert({l, x - 1});
    if (r > x)
        st.insert({x + 1, r});
}

int mex(set<pair<int, int>> &st, int x)
{
    if (isin(st, x) == st.end())
        return x;
    auto itr = isin(st, x);
    int r = itr->second;
    return ++r;
}

template <typename T>
struct SetRange
{
    int n;
    T inf, e;
    std::set<pair<T, T>> range;
    std::map<T, int> count;
    SetRange(const std::vector<T> _x, const T _inf, const T _e) : inf(_inf), e(_e)
    {
        n = _x.size();
        for (int i = 0; i < n; i++)
            count[_x[i]]++;

        T l = -inf, r = -inf;
        for (auto itr = count.begin(); itr != count.end(); ++itr)
        {
            if (itr->first == r + e)
                r = itr->first;
            else
            {
                range.insert({l, r});
                l = itr->first;
                r = itr->first;
            }
        }
        range.insert({l, r});
        range.insert({inf, inf});
    }

    auto isin(T x)
    {
        auto itr = range.lower_bound(make_pair(x + e, x + e));
        itr--;
        if ((itr->first <= x) && (x <= itr->second))
            return itr;
        return range.end();
    }

    bool add(T x)
    {
        count[x]++;
        if (isin(x) != range.end())
            return false;

        T l1 = -inf, r1 = -inf, l2 = inf, r2 = inf;
        if (isin(x - e) != range.end())
        {
            auto itr = isin(x - e);
            l1 = itr->first, r1 = itr->second;
        }
        if (isin(x + e) != range.end())
        {
            auto itr = isin(x + e);
            l2 = itr->first, r2 = itr->second;
        }
        if (r1 > -inf && l2 < inf)
        {
            range.erase({l1, r1});
            range.erase({l2, r2});
            range.insert({l1, r2});
        }
        else if (r1 > -inf)
        {
            range.erase({l1, r1});
            range.insert({l1, x});
        }
        else if (l2 < inf)
        {
            range.erase({l2, r2});
            range.insert({x, r2});
        }
        else
        {
            range.insert({x, x});
        }
        return true;
    }

    bool remove(T x)
    {
        if (isin(x) == range.end())
            return false;
        count[x]--;
        if (count[x] > 0)
            return true;
        auto itr = isin(x);
        T l = itr->first, r = itr->second;
        range.erase(*itr);
        if (l < x)
            range.insert({l, x - e});
        if (r > x)
            range.insert({x + e, r});
        return true;
    }

    T mex(T x)
    {
        if (isin(x) == range.end())
            return x;
        auto itr = isin(x);
        T r = itr->second;
        return r + e;
    }

    void print()
    {
        debug("debug");
        for (auto itr = range.begin(); itr != range.end(); ++itr)
        {
            debug(itr->first, itr->second);
        }
    }
};

// hhkb202_c
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &e : a)
        cin >> e;

    SetRange<int> st(vector<int>(), 1 << 30, 1);

    for (int i = 1; i <= n; i++)
    {
        st.add(a[i - 1]);
        cout << st.mex(0) << endl;
    }
}

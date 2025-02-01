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

#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

// 遅延伝搬SegmentTree
template <typename T>
class LazySegmentTree
{
    using F = std::function<T(T, T)>;

private:
    int n;
    int size;
    int height;

public:
    T IdentityNode; // 値データの単位元
    T IdentityLazy; // 遅延データの単位元

    F CombineNodeFunc; // 値データの作用
    F CombineLazyFunc; // 遅延データの伝搬作用
    F ReflectFunc;     // 遅延データを値データにどう反映させるか
    std::vector<T> node;
    std::vector<T> lazy;

    LazySegmentTree(int _n, const T &identityNode, const T &identityLazy,
                    const F &combineNodeFunc, const F &combineLazyFunc,
                    const F &reflectFunc)
    {
        n = _n;
        size = 1;
        height = 0;
        while (size < n)
            size <<= 1, height++;
        IdentityNode = identityNode;
        IdentityLazy = identityLazy;
        CombineNodeFunc = combineNodeFunc;
        CombineLazyFunc = combineLazyFunc;
        ReflectFunc = reflectFunc;
        node = std::vector<T>(2 * size, IdentityNode);
        lazy = std::vector<T>(2 * size, IdentityLazy);
    }

private:
    T reflect_lazy(int index)
    {
        return ReflectFunc(node[index], lazy[index]);
    }

    void propergate_from_top(int index)
    {
        index += size;
        for (int h = height; h > 0; h--)
        {
            int i = index >> h;
            if (lazy[i] != IdentityLazy)
            {
                lazy[i << 1 | 0] = CombineLazyFunc(lazy[i << 1 | 0], lazy[i]);
                lazy[i << 1 | 1] = CombineLazyFunc(lazy[i << 1 | 1], lazy[i]);
                node[i] = reflect_lazy(i);
                lazy[i] = IdentityLazy;
            }
        }
    }

    void update_from_bottom(int index)
    {
        index = (index + size) >> 1;
        while (index > 0)
        {
            node[index] = CombineNodeFunc(reflect_lazy(index << 1 | 0), reflect_lazy(index << 1 | 1));
            index >>= 1;
        }
    }

public:
    void build(std::vector<T> array)
    {
        for (size_t i = 0; i < array.size(); i++)
        {
            node[i + n] = array[i];
        }
        for (size_t i = n - 1; i > 0; i--)
        {
            size_t l = i << 1 | 0;
            size_t r = i << 1 | 1;
            node[i] = Func(node[l], node[r]);
        }
    }

    void update(int l, int r, T value)
    {
        propergate_from_top(l);
        propergate_from_top(r - 1);
        int l_lazy = l + size;
        int r_lazy = r + size;
        while (l_lazy < r_lazy)
        {
            if (l_lazy & 1)
            {
                lazy[l_lazy] = CombineLazyFunc(lazy[l_lazy], value);
                l_lazy++;
            }
            if (r_lazy & 1)
            {
                r_lazy--;
                lazy[r_lazy] = CombineLazyFunc(lazy[r_lazy], value);
            }
            l_lazy >>= 1;
            r_lazy >>= 1;
        }
        update_from_bottom(l);
        update_from_bottom(r - 1);
    }

    void update(int index, T value)
    {
        update(index, index + 1, value);
    }

    T fold(int l, int r)
    {
        propergate_from_top(l);
        propergate_from_top(r - 1);
        l += size;
        r += size;
        T value_l = IdentityNode;
        T value_r = IdentityNode;
        while (l < r)
        {
            if (l & 1)
            {
                value_l = CombineNodeFunc(value_l, reflect_lazy(l));
                l++;
            }
            if (r & 1)
            {
                r--;
                value_r = CombineNodeFunc(reflect_lazy(r), value_r);
            }
            l >>= 1;
            r >>= 1;
        }
        return CombineNodeFunc(value_l, value_r);
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    std::vector<std::tuple<int, int, long long>> t(m);
    std::vector<long long> a(n + 1, 0LL);
    for (int i = 0; i < m; i++)
    {
        int li, ri;
        long long ai;
        std::cin >> li >> ri >> ai;
        t[i] = {ri, li, ai}; // ソートするのでr先頭のほうが楽
        a[ri] += ai;
    }
    std::function<long long(long long, long long)> maxop = [](long long l, long long r)
    { return std::max(l, r); };
    std::function<long long(long long, long long)> addop = [](long long l, long long r)
    { return l + r; };
    /* dpするセグメント木
    for i = 1, ... n:
        for j = 0, ..., i-1:
            dp[i][j] = dp[i-1][j] // step 1
        dp[i][i] = max_{k\in[i-1]} dp[i-1][k] + a_{l, i} // step 2
        for j = 0, ..., i-1:
            dp[i][j] += sum (a_{l, i}) of at j // step 3
    */
    std::sort(t.begin(), t.end());
    LazySegmentTree<long long> dp(n + 1, 0LL, 0LL, maxop, addop, addop);
    int index = 0; // どの区間まで足したか覚える
    for (int i = 1; i <= n; i++)
    {
        dp.update(i, dp.fold(0, i) + a[i]);
        while (index < m && std::get<0>(t[index]) == i)
        {
            dp.update(std::get<1>(t[index]), i, std::get<2>(t[index]));
            index++;
        }
    }
    cout << dp.fold(0, n + 1) << '\n';

    return 0;
}
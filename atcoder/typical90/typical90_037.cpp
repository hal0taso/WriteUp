#include <bits/stdc++.h>
#include <iostream>
#include <numeric>
#include <cstdint>
#include <limits>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

template <typename T>
struct RMQ
{
    const T INF = numeric_limits<T>::min();
    int n;
    vector<T> dat, lazy;
    RMQ(int n_) : n(), dat(n_ * 4, INF), lazy(n_ * 4, INF)
    {
        int x = 1;
        while (n_ > x)
            x *= 2;
        n = x;
    }

    /* lazy eval */
    void eval(int k)
    {
        if (lazy[k] == INF)
            return; // 更新するものが無ければ終了
        if (k < n - 1)
        { // 葉でなければ子に伝搬
            lazy[k * 2 + 1] = lazy[k];
            lazy[k * 2 + 2] = lazy[k];
        }
        // 自身を更新
        dat[k] = lazy[k];
        lazy[k] = INF;
    }

    void update(int a, int b, T x, int k, int l, int r)
    {
        eval(k);
        if (a <= l && r <= b)
        { // 完全に内側の時
            lazy[k] = x;
            eval(k);
        }
        else if (a < r && l < b)
        {                                               // 一部区間が被る時
            update(a, b, x, k * 2 + 1, l, (l + r) / 2); // 左の子
            update(a, b, x, k * 2 + 2, (l + r) / 2, r); // 右の子
            dat[k] = max(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }
    void update(int a, int b, T x) { update(a, b, x, 0, 0, n); }
    void update(int a, T x) { update(a, a + 1, x, 0, 0, n); }

    T query_sub(int a, int b, int k, int l, int r)
    {
        eval(k);
        if (r <= a || b <= l)
        { // 完全に外側の時
            return INF;
        }
        else if (a <= l && r <= b)
        { // 完全に内側の時
            return dat[k];
        }
        else
        { // 一部区間が被る時
            T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return max(vl, vr);
        }
    }
    T query(int a, int b) { return query_sub(a, b, 0, 0, n); }

    /* debug */
    inline T operator[](int a) { return query(a, a + 1); }
    void print()
    {
        for (int i = 0; i < 2 * n - 1; ++i)
        {
            cout << (*this)[i];
            if (i != n)
                cout << ",";
        }
        cout << endl;
    }
};
void print(vector<ll> v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] < 0)
            cout << "-INF";
        else
            cout << v[i];
        if (i != v.size() - 1)
            cout << ",";
    }
    cout << endl;
}
int main()
{
    int W, N;
    ll INF = numeric_limits<ll>::min();
    cin >> W >> N;
    vector<int> L(N + 1), R(N + 1);
    vector<ll> V(N + 1);
    FOR(i, 1, N + 1)
    {
        cin >> L[i] >> R[i] >> V[i];
    }
    vector<RMQ<ll>> segdp(2, RMQ<ll>(W + 1));
    vector<vector<ll>> dp(2, vector<ll>(W + 1, INF));
    dp[0][0] = 0;
    int max_w = 0;
    segdp[0].update(0, 0);

    FOR(i, 1, N + 1)
    {
        max_w += R[i];
        REP(j, min(W, max_w) + 1)
        {
            // ll tmp = INF;
            // FOR(w, max(j - R[i], 0), j - L[i] + 1)
            // {
            //     tmp = max(tmp, dp[(i - 1) % 2][w] + V[i]);
            // }
            ll tmp = segdp[(i - 1) % 2].query(j - R[i], j - L[i] + 1) + V[i];
            dp[i % 2][j] = max(dp[(i - 1) % 2][j], tmp);
            // dp[i % 2][j] = max(dp[(i - 1) % 2][j], segdp[(i - 1) % 2].query(j - L[i], j - R[i] + 1) + V[i]);
            segdp[i % 2].update(j, dp[i % 2][j]);
        }
        // print(dp[i % 2]);
    }
    cout << max(dp[N % 2][W], -1LL) << endl;

    return 0;
}

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
#define REP(i, n) for (ll i = 0; i < n; ++i)

// 45度回転 https://kagamiz.hatenablog.com/entry/2014/12/21/213931
int main()
{
    int n, q;
    cin >> n >> q;
    vector<ll> x(n);
    vector<ll> y(n);
    vector<ll> rx(n);
    vector<ll> ry(n);
    map<ll, int> rx_i;
    map<ll, int> ry_i;
    REP(i, n)
    {
        cin >> x[i] >> y[i];
        rx[i] = x[i] - y[i];
        ry[i] = x[i] + y[i];
        rx_i[rx[i]] = i;
        ry_i[ry[i]] = i;
    }
    sort(rx.begin(), rx.end());
    sort(ry.begin(), ry.end());
    ll max_x = rx[n - 1], min_x = rx[0];
    ll max_y = ry[n - 1], min_y = ry[0];

    int ans_x;
    int ans_y;
    int ans_i;
    int qi;
    REP(i, q)
    {
        cin >> qi;
        qi--;
        ll qx = x[qi] - y[qi];
        ll qy = x[qi] + y[qi];
        cout << max(max(abs(qx - max_x), abs(qy - max_y)), max(abs(qx - min_x), abs(qy - min_y))) << endl;
    }

    return 0;
}
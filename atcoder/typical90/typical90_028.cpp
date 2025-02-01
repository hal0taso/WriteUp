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

vector<vector<int>> b(1000 + 1, vector<int>(1000 + 1, 0));

// imos法
// 問題: https://atcoder.jp/contests/typical90/tasks/typical90_ab
// 解説: https://twitter.com/e869120/status/1388262816101007363
int main()
{
    int n;
    cin >> n;
    int lx, ly, rx, ry;
    REP(i, n)
    {
        cin >> lx >> ly >> rx >> ry;
        b[lx][ly]++;
        b[rx][ry]++;
        b[lx][ry]--;
        b[rx][ly]--;
    }
    FOR(i, 1, 1000 + 1)
    {
        REP(j, 1000 + 1)
        b[i][j] += b[i - 1][j];
    }
    REP(i, 1000 + 1)
    {
        FOR(j, 1, 1000 + 1)
        b[i][j] += b[i][j - 1];
    }

    vector<int> ans(n + 1, 0);
    REP(x, 1000 + 1)
    {
        REP(y, 1000 + 1)
        {
            ans[b[x][y]]++;
        }
    }
    FOR(i, 1, n + 1)
    {
        cout << ans[i] << endl;
    }
    return 0;
}
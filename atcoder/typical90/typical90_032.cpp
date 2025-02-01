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

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    REP(i, n)
    REP(j, n)
    cin >> a[i][j];

    vector<int> v(n);
    REP(i, n)
    v[i] = i;

    vector<vector<bool>> edge(n, vector<bool>(n, false));
    int m;
    cin >> m;
    int x, y;
    REP(i, m)
    {
        cin >> x >> y;
        x--;
        y--;
        edge[x][y] = true;
        edge[y][x] = true;
    }
    int ans = 10010;
    do
    {
        bool c = false;
        int tmp = 0;
        REP(i, n)
        {
            if (i < n - 1 && edge[v[i]][v[i + 1]])
            {
                c = true;
                break;
            }
            tmp += a[v[i]][i];
        }
        if (c)
            continue;
        if (ans > tmp)
            ans = tmp;
    } while (std::next_permutation(v.begin(), v.end()));
    if (ans == 10010)
        ans = -1;

    cout << ans << endl;
    return 0;
}
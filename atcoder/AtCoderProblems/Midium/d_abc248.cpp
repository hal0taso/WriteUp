#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> idx(n + 1);
    int a;
    REP(i, n)
    {
        cin >> a;
        idx[a].push_back(i);
    }
    int q;
    cin >> q;
    int l, r, x;
    REP(i, q)
    {
        cin >> l >> r >> x;
        cout << lower_bound(idx[x].begin(), idx[x].end(), r) - lower_bound(idx[x].begin(), idx[x].end(), l - 1) << endl;
    }
}

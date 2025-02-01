#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n, k;
    cin >> n >> k;
    vector<string> s(n);
    vector<vector<int>> c(n, vector<int>(26, 0));

    REP(i, n)
    {
        cin >> s[i];
        for (auto si : s[i])
        {
            int idx = (si - 'a');
            c[i][idx]++;
        }
    }
    ll res = 0;
    REP(i, 1 << n)
    {
        vector<int> tmp(26, 0);
        ll t_ans = 0;
        REP(j, n)
        {
            if ((i >> j) & 1 == 1)
            {
                REP(l, 26)
                {
                    tmp[l] += c[j][l];
                }
            }
        }
        REP(l, 26)
        {
            if (tmp[l] == k)
            {
                t_ans++;
            }
        }
        if (t_ans > res)
        {
            res = t_ans;
        }
    }
    cout << res << endl;
}

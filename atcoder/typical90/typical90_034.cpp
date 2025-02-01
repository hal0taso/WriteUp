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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    REP(i, n)
    cin >> a[i];
    map<int, int> m;

    int cnt = 0;
    int ans = -1;
    int l = 0, r = 0;
    m[a[0]]++, cnt = 1;
    while (r < n)
    {
        if (cnt <= k)
        {
            if (ans < r - l + 1)
                ans = r - l + 1;
            r++;
            if (m[a[r]] == 0)
                cnt++;
            m[a[r]]++;
        }
        else
        {
            m[a[l]]--;
            if (m[a[l]] == 0)
                cnt--;
            l++;
        }
    }
    if (cnt <= k && ans < r - l)
        ans = r - l;
    cout << ans << endl;

    return 0;
}
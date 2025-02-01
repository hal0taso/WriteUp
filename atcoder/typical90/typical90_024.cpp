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
    vector<int> a(n), b(n);
    int d = 0;
    REP(i, n)
    cin >> a[i];

    REP(i, n)
    cin >> b[i];

    REP(i, n)
    d += max(a[i] - b[i], b[i] - a[i]);

    if (d <= k && (k - d) % 2 == 0)
    {
        puts("Yes");
    }
    else
        puts("No");
    return 0;
}
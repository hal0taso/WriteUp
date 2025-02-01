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
    int h, w;
    cin >> h >> w;
    if (h > 1 && w > 1)
        cout << ((h + 1) / 2) * ((w + 1) / 2) << endl;
    else
        cout << h * w << endl;

    return 0;
}
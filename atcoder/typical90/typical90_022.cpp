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

long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main()
{
    ll a, b, c;
    cin >> a >> b >> c;
    ll d = gcd(a, b);
    d = gcd(d, c);
    cout << (a / d - 1) + (b / d - 1) + (c / d - 1) << '\n';
    return 0;
}
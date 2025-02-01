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
    long long a, b;
    cin >> a >> b;
    if (a < b)
        swap(a, b);
    long long d = gcd(a, b);
    a /= d;
    if (a > (ll)1e18 / b)
        puts("Large");
    else
    {
        cout << a * b << endl;
    }
    return 0;
}
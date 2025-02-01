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

std::vector<int> count_prime_factor(int N)
{
    std::vector<int> c(N + 1, 0);
    for (int i = 2; i <= N; i++)
    {
        if (c[i] != 0)
            continue;
        for (int j = i; j <= N; j += i)
            c[j]++;
    }
    return c;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> c = count_prime_factor(n);
    int ans = 0;
    for (int i = 2; i <= n; i++)
    {
        if (c[i] >= k)
        {
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
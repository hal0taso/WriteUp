#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)
#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)
using vvll = vector<vector<ll>>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vvvb = vector<vector<vector<bool>>>;
using vvb = vector<vector<bool>>;
using vb = vector<bool>;
constexpr ll INF = 400000;

void print(vll v)
{
    for (auto vi : v)
    {
        cout << vi << ' ';
    }
    cout << '\n';
}

void print(vector<pair<ll, ll>> v)
{
    for (auto vi : v)
    {
        cout << vi.first << ' ';
    }
    cout << '\n';
    for (auto vi : v)
    {
        cout << vi.second << ' ';
    }
    cout << '\n';
}

int main()
{
    int n, q;
    cin >> n >> q;
    vll A(n + 1, 0), B(n + 1, 0);
    ll ans = 0;
    FOR(i, 1, n + 1)
    {
        cin >> A[i];
    }
    FOR(i, 1, n + 1)
    {
        B[i] = A[i] - A[i - 1];
    }
    FOR(i, 2, n + 1)
    {
        ans += abs(B[i]);
    }
    REP(i, q)
    {
        int l, r, v;
        cin >> l >> r >> v;
        r++;
        if (l > 1)
        {
            ans -= abs(B[l]);
            B[l] += v;
            ans += abs(B[l]);
        }
        if (r <= n)
        {
            ans -= abs(B[r]);
            B[r] -= v;
            ans += abs(B[r]);
        }
        cout << ans << '\n';
    }
    return 0;
}
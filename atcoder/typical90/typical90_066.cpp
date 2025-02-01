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
using vvd = vector<vector<double>>;
using vd = vector<double>;
using vvvb = vector<vector<vector<bool>>>;
using vvb = vector<vector<bool>>;
using vb = vector<bool>;
constexpr ll INF = 400000;

void print(vd v)
{
    for (auto vi : v)
    {
        cout << vi << ' ';
    }
    cout << '\n';
}

void print(vd v, int n)
{
    REP(i, n)
    {
        cout << v[i] << ' ';
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

constexpr int N = 100;
int main()
{
    int n;
    cin >> n;
    vi l(n + 1);
    vi r(n + 1);
    long double ans = 0;
    REP(i, n)
    {
        cin >> l[i] >> r[i];
    }
    REP(i, n)
    {
        FOR(j, i + 1, n)
        {
            for (int a = l[i]; a <= r[i]; a++)
            {
                for (int b = l[j]; b <= r[j]; b++)
                {
                    if (a > b)
                        ans += (long double)1 / ((long double)(r[i] - l[i] + 1) * (r[j] - l[j] + 1));
                }
            }
        }
    }
    cout << std::fixed;
    std::cout << std::setprecision(9);
    cout << ans << '\n';

    return 0;
}
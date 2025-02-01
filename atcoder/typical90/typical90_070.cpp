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

struct Point
{
    int x, y;
    Point(int x_, int y_) : x(x_), y(y_) {}
};

// \min \sum_{i = 1}^n |a_i - x|
int main()
{
    int n;
    cin >> n;
    vector<long double> x(n), y(n);
    long double a = 0, b = 0;
    REP(i, n)
    {
        cin >> x[i] >> y[i];
        a += x[i];
        b += y[i];
    }
    sort(all(x));
    sort(all(y));
    if (n % 2 == 1)
    {
        a = x[n / 2];
        b = y[n / 2];
    }
    else
    {
        a = (x[n / 2 - 1] + x[n / 2]) / 2.0;
        b = (y[n / 2 - 1] + y[n / 2]) / 2.0;
    }
    // a /= (long double)n;
    // b /= (long double)n;
    long double ans = 0;
    REP(i, n)
    {
        ans += max(a - x[i], x[i] - a);
        ans += max(b - y[i], y[i] - b);
    }
    // cout << a << ',' << b << '\n';
    cout << (long long)ans << '\n';

    return 0;
}
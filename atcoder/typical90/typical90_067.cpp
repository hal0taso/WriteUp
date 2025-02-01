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

ll powmod(ll a, ll b, ll mod)
{
    ll res = 1;
    for (; b; b >>= 1)
    {
        if (b & 1)
        {
            res = res * a % mod;
        }
        a = a * a % mod;
    }
    return res;
}

ll pow(ll a, ll b)
{
    ll res = 1;
    for (; b; b >>= 1)
    {
        if (b & 1)
        {
            res = res * a;
        }
        a = a * a;
    }
    return res;
}

int main()
{
    string s;
    int k;
    cin >> s >> k;
    reverse(all(s));
    while (k > 0)
    {
        int n = s.size();
        ll tmp = 0;
        REP(i, n)
        {
            tmp += (s[i] - '0') * pow(8LL, i);
        }
        string t = "";
        while (tmp > 0)
        {
            ll ti = tmp % 9LL;
            if (ti == 8)
                ti = 5;
            tmp -= ti;
            tmp /= 9;
            t += (char)(ti + '0');
        }
        if (t == "")
            t = "0";
        s = t;
        k--;
    }
    reverse(all(s));

    cout << s << endl;

    return 0;
}
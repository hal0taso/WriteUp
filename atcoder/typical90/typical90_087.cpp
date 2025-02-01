#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)
#define RFOR(i, a, b) for (ll i = b - 1; i >= a; i--)
#define RREP(i, n) for (ll i = n - 1; i >= 0; i--)
#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)
using vvi = vector<vector<int>>;
using vi = vector<int>;

int count(vector<vector<ll>> &dist, ll p)
{
    int res = 0;
    ll V = dist.size();
    REP(i, V)
    {
        FOR(j, i + 1, V)
        {
            if (dist[i][j] <= p)
                res++;
        }
    }
    return res;
}

int warshall_floyd(vector<vector<ll>> dist, ll X, ll p)
{
    int V = dist.size();
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == -1)
                dist[i][j] = X;
        }
    }
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    return count(dist, p);
    // return dist;
}

int main()
{
    ll n, p, k;
    cin >> n >> p >> k;
    vector<vector<ll>> a(n, vector<ll>(n, 0));
    REP(i, n)
    REP(j, n)
    cin >> a[i][j];

    // check not inifinity
    int c = warshall_floyd(a, p + 1, p);
    if (c == k)
    {
        puts("Infinity");
        return 0;
    }
    // else if (c > k)
    // {
    //     cout << 0 << '\n';
    //     return 0;
    // }
    else
    {
        ll lb = 0LL, ub = p + 1;
        while (lb + 1 < ub)
        {
            ll mid = (lb + ub) / 2;
            c = warshall_floyd(a, mid, p);
            if (c < k)
                ub = mid;
            else
                lb = mid;
        }
        if (warshall_floyd(a, lb, p) != k)
        {
            cout << 0 << '\n';
            return 0;
        }
        ll r = lb;
        lb = 0LL, ub = r;
        while (lb + 1 < ub)
        {
            ll mid = (lb + ub) / 2;
            c = warshall_floyd(a, mid, p);
            if (c == k)
                ub = mid;
            else
                lb = mid;
        }
        ll l = lb;
        // cout << "r=" << r << ",l=" << l << '\n';
        cout << r - l << '\n';
        return 0;
    }

    return 0;
}

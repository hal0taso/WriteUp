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
    int h, w;
    cin >> h >> w;
    vvi p = vvi(h, vi(w));
    REP(i, h)
    REP(j, w)
    cin >> p[i][j];
    int ans = 0;
    REP(k, 1 << h)
    {
        vi tgt_i;
        vi v = vi(h * w + 1, 0);
        REP(i, h)
        if ((k >> i) & 1 == 1)
            tgt_i.push_back(i);
        REP(j, w)
        {
            int idx = 0;
            for (int i : tgt_i)
            {
                if (idx == 0)
                    idx = p[i][j];
                else
                {
                    if (idx != p[i][j])
                    {
                        idx = 0;
                        break;
                    }
                }
            }
            if (idx > 0)
                v[idx]++;
        }
        sort(all(v));
        int tmp = tgt_i.size() * v[h * w];
        if (ans < tmp)
            ans = tmp;
    }
    cout << ans << '\n';
}
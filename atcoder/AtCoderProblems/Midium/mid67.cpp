#include <bits/stdc++.h>
#include <atcoder/modint>

using namespace std;
using namespace atcoder;

using mint = modint998244353;

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
using vvll = vector<vector<ll>>;
using vll = vector<ll>;
constexpr long long INF = 20000000;

// constexpr int MOD = 1000000000 + 7;

int main()
{
    vector<string> S(3);
    vector<int> cnt(3, 0);
    for (string &s : S)
        cin >> s;
    int now = 0;
    while (cnt[now] < (int)S[now].size())
    {
        int next = S[now][cnt[now]] - 'a';
        cnt[now]++;
        now = next;
    }
    cout << (char)('A' + now) << '\n';
    return 0;
}

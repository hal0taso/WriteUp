#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

// Running time per a query: O(\alpha(N)), where \alpha is an inverse Ackermann function
struct UnionFind
{
    vector<ll> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(ll N) : par(N)
    { //最初は全てが根であるとして初期化
        for (ll i = 0; i < N; i++)
            par[i] = i;
    }

    ll root(ll x)
    { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x)
            return x;
        return par[x] = root(par[x]);
    }

    void unite(ll x, ll y)
    {                    // xとyの木を併合
        ll rx = root(x); // xの根をrx
        ll ry = root(y); // yの根をry
        if (rx == ry)
            return;   // xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; // xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(ll x, ll y)
    { // 2つのデータx, yが属する木が同じならtrueを返す
        ll rx = root(x);
        ll ry = root(y);
        return rx == ry;
    }
};

int main()
{
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<int>> board(h, vector<int>(w, 0));
    UnionFind uf(h * w);
    int x, ra, ca, rb, cb;

    REP(i, q)
    {
        cin >> x;
        if (x == 1)
        {
            cin >> ra >> ca;
            ra--;
            ca--;
            board[ra][ca] = 1;
            for (int r : {ra - 1, ra + 1})
            {
                int c = ca;
                if (r >= 0 && r < h && c >= 0 && c < w && board[r][c] > 0)
                {
                    uf.unite(ra * w + ca, r * w + c);
                }
            }
            for (int c : {ca - 1, ca + 1})
            {
                int r = ra;
                if (r >= 0 && r < h && c >= 0 && c < w && board[r][c] > 0)
                {
                    uf.unite(ra * w + ca, r * w + c);
                }
            }
        }
        else
        {
            cin >> ra >> ca >> rb >> cb;
            ra--;
            ca--;
            rb--;
            cb--;
            if (board[ra][ca] > 0 && board[rb][cb] > 0 && uf.same(ra * w + ca, rb * w + cb))
                puts("Yes");
            else
                puts("No");
        }
    }
    return 0;
}

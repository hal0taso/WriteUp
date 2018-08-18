// d_abc106.cpp
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

#define FOR(i,a,b) for(i = a; i < b; ++i)
#define REP(i,n)   for(i = 0; i < n; ++i)

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;


vector<vector<int>> sum;
ll N, M, Q;

void makeSumTable(vector<int> L, vector<int> R)
{
    ll i, j;

    sum = vector<vector<int>> (N + 1, vector<int>(N + 1, 0));

    REP(i, M){
        ++sum[L[i]][R[i]];
    }

    FOR(i, 1, N + 1){
        FOR(j, 1, N + 1){
            sum[i][j] += sum[i - 1][j];
            sum[i][j] += sum[i][j - 1];
            sum[i][j] -= sum[i - 1][j - 1];
        }
    }
}

int getSum(int L, int R){
    int ans = sum[R][R] - sum[R][L - 1] - sum[L - 1][R] + sum[L - 1][L - 1];
    return ans;
}

int main()
{
    ll i;

    // cin >> N >> M >> Q;
    scanf("%d %d %d", N, M, Q);

    vector<int> L(M);
    vector<int> R(M);
    REP(i, M){
        // cin >> L[i] >> R[i];
        scanf("%d %d", &L[i], &R[i]);
    }

    vector<int> p(Q);
    vector<int> q(Q);
    REP(i, Q){
        // cin >> p[i] >> q[i];
        scanf("%d %d", &p[i], &q[i]);
    }

    makeSumTable(L, R);

    int ans;
    REP(i, Q){
        ans = getSum(p[i], q[i]);
        // cout << ans << endl;
        printf("%d\n", ans);
    }
}

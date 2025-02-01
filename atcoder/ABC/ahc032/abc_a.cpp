#include <bits/stdc++.h>
#include <sys/time.h>
// #include <random>
// #include <algorithm>
using namespace std;

// using mint = modint1000000007;
constexpr long long TIME_LIMIT = 1700;
random_device seed_gen;
mt19937 engine(seed_gen());
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define RFOR(i, a, b) for (int i = b - 1; i >= a; i--)
#define RREP(i, n) for (int i = n - 1; i >= 0; i--)
#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vvll = vector<vector<ll>>;
using vll = vector<ll>;
constexpr long long INF = (1LL << 60);
void debug_out()
{
  cerr << endl;
}

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
  cerr << H << " ";
  debug_out(T...);
}

#define debug(...) debug_out(__VA_ARGS__)
constexpr int MOD = 998244352;

map<tuple<int, int, int, int>, ull> hashtable;

struct Status
{
  vector<vector<ll>> a;
  ll score;
  ll capa;
  ll cost;
  ull zbhash;
  vector<vector<vector<int>>> ans;
  vector<vector<ll>> rect_score;

  Status(int _m, int _k, const vector<vector<ll>> &_a, ll _score = 0, ll _cost = 0, ull _zbhash = 0) : score(0), capa(_k), cost(0), zbhash(0)
  {

    int n = (int)_a.size();
    a = vector<vector<ll>>(n, vector<ll>(n, 0));
    REP(i, n)
    REP(j, n)
    a[i][j] = _a[i][j];

    rect_score.resize(n - 3, vector<ll>(n - 3, 0));
    REP(i, (int)a.size())
    {
      REP(j, (int)a.size())
      {
        score += a[i][j] % MOD;
        REP(x, 3)
        {
          REP(y, 3)
          {
            if (i - x > 0 && j - y > 0 && i - x < (int)a.size() - 3 && j - y < (int)a.size() - 3)
              rect_score[i - x][i - y] += a[i][j] % MOD;
          }
        }
      }
    }
    ans.assign(_a.size(), vector<vector<int>>(_a.size(), vector<int>(_m, 0)));
  }

  Status copy()
  {
    Status s(20, 81, a, score, cost, zbhash);
    s.ans = ans;
    s.rect_score = rect_score;
    return s;
  }

  bool is_valid(int i, int j, int t)
  {
    if (i < 0 || i >= (int)a.size() - 3 || j < 0 || j >= (int)a.size() - 3)
    {
      return false;
    }
    if (t > 0 && capa < t)
    {
      return false;
    }
    if (t < 0 && cost + t < 0)
      return false;
    return true;
  }

  void stamp(int x, int y, int m, int t, vector<vector<ll>> &s)
  {
    // debug("Stamping...", x, y, m, t);
    if (!is_valid(x, y, t))
    {
      return;
    }
    if (ans[x][y][m] > 0)
    {
      tuple<int, int, int, int> key = {x, y, m, ans[x][y][m]};
      if (hashtable.count(key) == 0)
      {
        hashtable[key] = engine() % (1ULL << 60);
      }
      zbhash ^= hashtable[key];
    }
    ans[x][y][m] += t;
    cost += t;
    capa -= t;
    REP(i, 3)
    {
      REP(j, 3)
      {
        score -= a[x + i][y + j];
        a[x + i][y + j] = (a[x + i][y + j] + s[i][j]) % MOD;
        score += a[x + i][y + j];
      }
    }
    tuple<int, int, int, int> key = {x, y, m, ans[x][y][m]};
    if (hashtable.count(key) == 0)
    {
      hashtable[key] = engine() % (1ULL << 60);
    }
    zbhash ^= hashtable[key];
  }

  void undo(int x, int y, int m, int t, vector<vector<ll>> &s)
  {
    // debug("Undoing...", x, y, m, t);
    if (!is_valid(x, y, -t))
    {
      return;
    }
    if (ans[x][y][m] > 0)
    {
      tuple<int, int, int, int> key = {x, y, m, ans[x][y][m]};
      if (hashtable.count(key) == 0)
      {
        hashtable[key] = engine() % (1ULL << 60);
      }
      zbhash ^= hashtable[key];
    }
    ans[x][y][m] -= t;
    cost -= t;
    capa += t;
    REP(i, 3)
    {
      REP(j, 3)
      {
        score -= a[x + i][y + j];
        a[x + i][y + j] = (a[x + i][y + j] - s[i][j]) % MOD;
        score += a[x + i][y + j];
      }
    }
    tuple<int, int, int, int> key = {x, y, m, ans[x][y][m]};
    if (hashtable.count(key) == 0)
    {
      hashtable[key] = engine() % (1ULL << 60);
    }
    zbhash ^= hashtable[key];
  }

  void output()
  {
    cout << cost << endl;
    REP(i, (int)ans.size())
    {
      REP(j, (int)ans[i].size())
      {
        REP(k, (int)ans[i][j].size())
        {
          if (ans[i][j][k] > 0)
          {
            REP(_, ans[i][j][k])
            {
              cout << k << " " << i << " " << j << endl;
            }
          }
        }
      }
    }
  }
};

vector<vector<vector<vector<ll>>>> gen_cand(vector<vector<vector<ll>>> &s, int k)
{
  // cand[m][t][i][j]: m番目のスタンプをt回使って(i, j)にスタンプを押す
  vector<vector<vector<vector<ll>>>> cand(s.size());
  REP(m, (int)s.size())
  {
    vector<vector<ll>> tmp = s[m];
    REP(t, k)
    {
      cand[m].push_back(tmp);
      REP(i, 3)
      {
        REP(j, 3)
        {
          tmp[i][j] = (tmp[i][j] + s[m][i][j]) % MOD;
        }
      }
    }
  }

  return cand;
}
ll getTime()
{
  struct timeval tv;
  gettimeofday(&tv, NULL);
  long long result = tv.tv_sec * 1000LL + tv.tv_usec / 1000LL;
  // cerr << result << endl;
  return result;
}

void solve(int n, int m, int k, vector<vector<ll>> &a, vector<vector<vector<ll>>> &s)
{
  vector<vector<vector<vector<ll>>>> cand = gen_cand(s, k);
  Status init(m, k, a);
  int beam_width = 20;
  // ビームサーチ
  // a: NxNの行列
  // s: Mx3x3の行列
  // beam_width: ビーム幅
  // k: 最大操作可能回数
  vector<Status> beam;
  beam.push_back(init);
  ll start_time = getTime(); // 開始時刻
  Status best = init.copy();
  while (true)
  {
    // debug("Best...\t\t", best.score, best.cost, best.capa);
    // debug("Processing...\t", beam[0].score, beam[0].cost, beam[0].capa);
    ll now_time = getTime(); // 現在時刻
    if (now_time - start_time > TIME_LIMIT)
      break;
    vector<Status> next_beam;
    set<ull> zbhashes;
    // next_beam.push_back(beam[0]);
    for (auto &status : beam)
    {

      debug("Processing...", status.score, status.cost, status.capa);
      // rect_score が低い候補をbeam_widthだけ選ぶ
      priority_queue<pair<ll, pair<int, int>>> pq;
      REP(i, n - 3)
      {
        REP(j, n - 3)
        {
          pq.push({-status.rect_score[i][j], {i, j}});
          // pq.push({random() % 100, {i, j}});
        }
      }
      // rect_score が低い候補のうち、操作済みの箇所を選び、操作をキャンセルする
      priority_queue<pair<ll, tuple<int, int, int, int>>> pq2;
      REP(i, n - 3)
      {
        REP(j, n - 3)
        {
          REP(mi, m)
          {
            if (status.ans[i][j][mi] > 0)
            {
              // 矩形のスコアが最も低い箇所の操作をキャンセルする
              // int n_cancels = random() % status.ans[i][j][mi] + 1;
              // pq2.push({status.rect_score[i][j], {mi, status.ans[i][j][mi], i, j}});
              // 操作回数が最も多い特定の位置のスタンプをキャンセルする
              int n_cancels = random() % status.ans[i][j][mi] + 1;
              pq2.push({status.ans[i][j][mi], {mi, n_cancels, i, j}});
            }
          }
        }
      }
      vector<tuple<int, int, int, int>> cancel_cand;
      REP(_, beam_width)
      {
        if (pq2.empty())
          break;
        auto [__, tup] = pq2.top();
        pq2.pop();
        cancel_cand.push_back(tup);
      }
      vector<pair<int, int>> process_cand;
      REP(_, beam_width)
      {
        if (pq.empty())
          break;
        auto [__, ij] = pq.top();
        pq.pop();
        process_cand.push_back(ij);
      }
      if (!cancel_cand.empty())
      {
        // for (auto &[mi, t, i, j] : cancel_cand)
        // {
        //   for (auto &[x, y] : process_cand)
        //   {
        // cancel_candからsample関数を使ってランダムにbeam_width個の要素を選ぶ.
        int size_cancel = cancel_cand.size();
        int size_process = process_cand.size();
        REP(_, beam_width)
        {
          if (size_cancel == 0 || size_process == 0)
            break;
          int idx_cancel = random() % size_cancel;
          int idx_process = random() % size_process;
          auto [mi, t, i, j] = cancel_cand[idx_cancel];
          auto [x, y] = process_cand[idx_process];
          // 他のスタンプを使ってキャンセルした箇所にスタンプを押す
          int l = random() % m;
          while (l == mi)
          {
            l = random() % m;
          }
          // REP(l, m)
          // {
          if (l == mi)
            continue;
          if (status.capa == 0)
            continue;
          int u = random() % status.capa + 1;
          Status next = status.copy();
          // debug("Undoing...", i, j, mi, t);
          next.undo(i, j, mi, t, cand[mi][t - 1]);
          // debug("Stamping...", x, y, l, u);
          next.stamp(x, y, l, u, cand[l][u - 1]);
          if (zbhashes.count(next.zbhash) == 0)
          {
            next_beam.push_back(next);
            zbhashes.insert(next.zbhash);
          }
          // }
        }
      }
      else
      {

        for (auto [x, y] : process_cand)
        {
          int l = random() % m;
          // REP(l, m)
          // {
          if (status.capa == 0)
            continue;
          int u = random() % status.capa + 1;
          Status next = status.copy();
          next.stamp(x, y, l, u, cand[l][u - 1]);
          if (zbhashes.count(next.zbhash) == 0)
          {
            next_beam.push_back(next);
            zbhashes.insert(next.zbhash);
          }
          // }
        }
      }
    }
    sort(all(next_beam), [](Status &a, Status &b)
         { return a.score > b.score; });
    beam = vector<Status>(next_beam.begin(), next_beam.begin() + beam_width);
    if (best.score < beam[0].score)
    {
      best = beam[0];
    }
  }
  best.output();
}

int main()
{
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<ll>> a(n, vector<ll>(n));
  REP(i, n)
  {
    REP(j, n)
    {
      cin >> a[i][j];
    }
  }
  vector<vector<vector<ll>>> s(m, vector<vector<ll>>(3, vector<ll>(3)));
  REP(i, m)
  {
    REP(j, 3)
    {
      REP(l, 3)
      {
        cin >> s[i][j][l];
      }
    }
  }
  solve(n, m, k, a, s);
}

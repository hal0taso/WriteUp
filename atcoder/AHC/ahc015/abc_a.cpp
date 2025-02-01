#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

const int N = 10;
const int M = 3;

// Union-Find
struct UnionFind
{
  vector<int> par, rank, siz;

  // 構造体の初期化
  UnionFind(int n) : par(n, -1), rank(n, 0), siz(n, 1) {}

  // 根を求める
  int root(int x)
  {
    if (par[x] == -1)
      return x; // x が根の場合は x を返す
    else
      return par[x] = root(par[x]); // 経路圧縮
  }

  // x と y が同じグループに属するか (= 根が一致するか)
  bool issame(int x, int y)
  {
    return root(x) == root(y);
  }

  // x を含むグループと y を含むグループを併合する
  bool unite(int x, int y)
  {
    int rx = root(x), ry = root(y); // x 側と y 側の根を取得する
    if (rx == ry)
      return false; // すでに同じグループのときは何もしない
    // union by rank
    if (rank[rx] < rank[ry])
      swap(rx, ry); // ry 側の rank が小さくなるようにする
    par[ry] = rx;   // ry を rx の子とする
    if (rank[rx] == rank[ry])
      rank[rx]++;       // rx 側の rank を調整する
    siz[rx] += siz[ry]; // rx 側の siz を調整する
    return true;
  }

  // x を含む根付き木のサイズを求める
  int size(int x)
  {
    return siz[root(x)];
  }
};

typedef struct Input
{
  vector<int> fs;
  vector<int> ps;
} Input;

class State
{
public:
  vector<int> fs;
  vector<int> ps;
  vector<vector<int>> board;
  int t;
  pair<int, int> last;
  State(Input &input)
  {
    board = vector<vector<int>>(N, vector<int>(N, 0));
    last = make_pair((input.ps[0] - 1) / N, (input.ps[0] - 1) % N);
    board[last.first][last.second] = input.fs[0];
    t = 0;
    fs = input.fs;
    ps = input.ps;
  }
  /*   State(Input &input)
    {
      board = vector<vector<int>>(N, vector<int>(N, 0));
      t = 0;
      fs = input.fs;
      ps = input.ps;
    } */
  State(Input &input, vector<vector<int>> &board, int t)
  {
    this->board = vector<vector<int>>(N, vector<int>(N, 0));
    REP(i, N)
    {
      REP(j, N)
      {
        this->board[i][j] = board[i][j];
      }
    }
    this->t = t;
    fs = input.fs;
    ps = input.ps;
  }
  void apply_move(char dir)
  {
    if (dir == 'F')
    {
      REP(j, N)
      {
        int k = 0;
        REP(i, N)
        {
          if (board[i][j] != 0)
          {
            board[k][j] = board[i][j];
            if (k != i)
            {
              board[i][j] = 0;
            }
            k++;
          }
        }
      }
    }
    else if (dir == 'R')
    {
      REP(i, N)
      {
        int k = N - 1;
        for (int j = N - 1; j >= 0; j--)
        {
          if (board[i][j] != 0)
          {
            board[i][k] = board[i][j];
            if (k != j)
            {
              board[i][j] = 0;
            }
            k--;
          }
        }
      }
    }
    else if (dir == 'L')
    {
      REP(i, N)
      {
        int k = 0;
        REP(j, N)
        {
          if (board[i][j] != 0)
          {
            board[i][k] = board[i][j];
            if (k != j)
            {
              board[i][j] = 0;
            }
            k++;
          }
        }
      }
    }
    else if (dir == 'B')
    {
      REP(j, N)
      {
        int k = N - 1;
        for (int i = N - 1; i >= 0; i--)
        {
          if (board[i][j] != 0)
          {
            board[k][j] = board[i][j];
            if (k != i)
            {
              board[i][j] = 0;
            }
            k--;
          }
        }
      }
    }
    t++;
    int p = 0;
    REP(i, N)
    {
      REP(j, N)
      {
        if (board[i][j] == 0)
        {
          p++;
          if (p == ps[t])
          {
            board[i][j] = fs[t];
            last = make_pair(i, j);
          }
        }
      }
    }
  }

  /*   void apply_move(char dir, int psi)
    {
      int p = 0;
      REP(i, N)
      {
        REP(j, N)
        {
          if (board[i][j] == 0)
          {
            p++;
            if (p == psi)
            {
              board[i][j] = fs[t];
              last = make_pair(i, j);
            }
          }
        }
      }
      if (dir == 'F')
      {
        REP(j, N)
        {
          int k = 0;
          REP(i, N)
          {
            if (board[i][j] != 0)
            {
              board[k][j] = board[i][j];
              if (k != i)
              {
                board[i][j] = 0;
              }
              k++;
            }
          }
        }
      }
      else if (dir == 'R')
      {
        REP(i, N)
        {
          int k = N - 1;
          for (int j = N - 1; j >= 0; j--)
          {
            if (board[i][j] != 0)
            {
              board[i][k] = board[i][j];
              if (k != j)
              {
                board[i][j] = 0;
              }
              k--;
            }
          }
        }
      }
      else if (dir == 'L')
      {
        REP(i, N)
        {
          int k = 0;
          REP(j, N)
          {
            if (board[i][j] != 0)
            {
              board[i][k] = board[i][j];
              if (k != j)
              {
                board[i][j] = 0;
              }
              k++;
            }
          }
        }
      }
      else if (dir == 'B')
      {
        REP(j, N)
        {
          int k = N - 1;
          for (int i = N - 1; i >= 0; i--)
          {
            if (board[i][j] != 0)
            {
              board[k][j] = board[i][j];
              if (k != i)
              {
                board[i][j] = 0;
              }
              k--;
            }
          }
        }
      }
      t++;
    } */

  int compute_score()
  {
    UnionFind uf(N * N);
    int score = 0;
    REP(i, N)
    {
      REP(j, N)
      {
        if (i < N - 1)
        {
          if (board[i][j] != 0 && board[i][j] == board[i + 1][j])
          {
            uf.unite(i * N + j, (i + 1) * N + j);
          }
        }
        if (j < N - 1)
        {
          if (board[i][j] != 0 && board[i][j] == board[i][j + 1])
          {
            uf.unite(i * N + j, i * N + j + 1);
          }
        }
      }
    }
    REP(i, N)
    {
      REP(j, N)
      {
        if (board[i][j] != 0 && uf.root(i * N + j) == i * N + j)
        {
          score += uf.size(i * N + j) * uf.size(i * N + j);
        }
      }
    }
    return score;
  }
};

vector<vector<int>> board(N, vector<int>(N, 0));

using Output = vector<char>;

pair<int, char> solve(Input &input, Output &output, int t)
{
  string cand = "FBLR";
  char ret;
  State state(input);
  // Output output;
  int outer_score = 0;
  int psi;
  int tmp;
  int param = 2;
  REP(i, t)
  {
    state.apply_move(output[i]);
  }
  vector<vector<char>> branch(4 * 4);
  REP(i, 4)
  {
    REP(k, 4)
    {
      REP(j, t)
      {
        branch[4 * i + k].push_back(output[j]);
      }
    }
  }

  REP(i, 4)
  {
    REP(j, 4)
    {
      char ans;
      int score;
      State cand_state(input, state.board, t);
      branch[4 * i + j].push_back(cand[i]);
      branch[4 * i + j].push_back(cand[j]); // 2nd candidates
      cand_state.apply_move(cand[i]);
      cand_state.apply_move(cand[j]);
      FOR(_t, t + 3, N * N)
      {
        // cout << "[debug]" << psi << endl;
        score = 0;
        for (char s : cand)
        {
          State cand_state2(input, cand_state.board, cand_state.t);
          cand_state2.apply_move(s);
          tmp = cand_state2.compute_score();
          // cout << "score" << tmp << end;
          if (tmp > score)
          {
            ans = s;
            score = tmp;
          }
        }
        cand_state.apply_move(ans);
        branch[4 * i + j].push_back(ans);
        // cout << ans << endl;
        // flush(cout);
        // cin >> psi;
        // input.ps.push_back(psi);
      }
      tmp = cand_state.compute_score();
      if (tmp > outer_score)
      {
        ret = cand[i];
        outer_score = tmp;
      }
    }
  }
  return make_pair(outer_score, ret);

  // FOR(i, 1, N * N)
  // {
  //   // cout << "[debug]" << psi << endl;
  //   score = 0;
  //   for (char s : cand)
  //   {
  //     State cand_state(input, state.board, state.t);
  //     cand_state.apply_move(s);
  //     tmp = cand_state.compute_score();
  //     // cout << "score" << tmp << end;
  //     if (tmp > score)
  //     {
  //       ans = s;
  //       score = tmp;
  //     }
  //   }
  //   state.apply_move(ans);
  //   // output.push_back(ans);
  //   // cout << ans << endl;
  //   flush(cout);
  //   cin >> psi;
  //   input.ps.push_back(psi);
  // }
  // return;
}

int main()
{
  int PARA = 2;
  int fsi;
  // vector<int> fs(N * N);
  // vector<int> ps;
  vector<Input> vec_input(PARA);
  // Input input;
  REP(i, N * N)
  {
    cin >> fsi;
    REP(j, PARA)
    {
      vec_input[j].fs.push_back(fsi);
    }
  }
  std::random_device rnd; // 非決定的な乱数生成器を生成
  std::mt19937 mt(rnd()); //  メルセンヌ・ツイスタの32ビット版、引数は初期シード値
                          // [0, 99] 範囲の一様乱数
  FOR(t, 1, N * N + 1)
  {
    std::uniform_int_distribution<> rand100(1, 101 - t);
    REP(j, PARA)
    {
      int y = rand100(mt);
      // cout << y << ',';
      vec_input[j].ps.push_back(y);
    }
    // cout << endl;
  }
  int psi;
  cin >> psi;
  REP(j, PARA)
  {
    vec_input[j].ps[0] = psi;
  }
  Output output;
  int score = 0;
  char result;
  FOR(t, 1, N * N)
  {
    REP(j, PARA)
    {
      pair<int, char> ans = solve(vec_input[j], output, t - 1);
      if (score < ans.first)
      {
        score = ans.first;
        result = ans.second;
      }
    }
    cout << result << endl;
    output.push_back(result);

    cin >> psi;
    REP(j, PARA)
    vec_input[j].ps[t] = psi;
  }

  // cout << "YES" << endl;
  return 0;
}

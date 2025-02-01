#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)

int main()
{
  int64_t N, M;
  std::cin >> N >> M;
  std::vector<int64_t> A(N);
  std::vector<int64_t> B(N);
  for (int64_t i = 0; i < N; i++)
  {
    std::cin >> A.at(i) >> B.at(i);
  }

  // DPテーブル
  std::vector<std::vector<int64_t>> dp(N + 1, std::vector<int64_t>(M + 1, -1));
  // 初期条件
  dp.at(0).at(0) = 0;

  // 遷移
  for (int64_t i = 1; i <= N; i++)
  {
    for (int64_t j = 0; j <= M; j++)
    {
      if (dp.at(i - 1).at(j) >= 0)
      {
        // i番目の要素を使わずに済む場合
        dp.at(i).at(j) = B.at(i - 1);
      }
      else if (j < A.at(i - 1) || dp.at(i).at(j - A.at(i - 1)) <= 0)
      {
        // i番目の要素を何個使っても総和をちょうどjにできない
        dp.at(i).at(j) = -1;
      }
      else
      {
        // i番目の要素をいくつか使って総和をちょうどjにできる
        dp.at(i).at(j) = dp.at(i).at(j - A.at(i - 1)) - 1;
      }
    }
  }

  // 出力
  if (dp.at(N).at(M) >= 0)
  {
    std::cout << "Yes" << std::endl;
  }
  else
  {
    std::cout << "No" << std::endl;
  }

  return 0;
}
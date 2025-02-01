#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <bitset>
#include <sstream>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main()
{
  int N, K;
  string S;
  cin >> N >> K >> S;
  string ans(K, 'a');
  vector<vector<int>> pos(N + 1, vector<int>(26, N));
  for (int i = N - 1; i >= 0; i--)
  {
    for (int j = 0; j < 26; j++)
    {
      pos[i][j] = pos[i + 1][j];
    }
    pos[i][S[i] - 'a'] = i;
  }
  int i = 0;
  int cnt = 0;
  while (i < N && cnt < K)
  {
    for (int j = 0; j < 26; j++)
    {
      if (pos[i][j] < N - (K - cnt - 1))
      {
        ans[cnt] = 'a' + j;
        i = pos[i][j] + 1;
        break;
      }
    }
    cnt++;
  }
  cout << ans << endl;
  return 0;
}

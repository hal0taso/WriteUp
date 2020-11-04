#include <iostream>
#include <vector>
using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  long N, M, C;
  cin >> N >> M >> C;
  vector<long> B(M);
  long a;
  long cnt = 0;
  long accum;
  REP(i, M) { cin >> B[i]; }
  REP(i, N) {
    accum = C;
    REP(j, M) {
      cin >> a;
      accum += a * B[j];
    }
    if (accum > 0) {
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}

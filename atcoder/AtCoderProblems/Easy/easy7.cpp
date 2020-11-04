#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  vector<vector<int>> A(3, vector<int>(3));
  REP(i, 3) {
    REP(j, 3) { cin >> A[i][j]; }
  }
  vector<int>::iterator itr;

  int N;
  int b;
  cin >> N;

  REP(i, N) {
    cin >> b;
    REP(j, 3) {
      itr = find(A[j].begin(), A[j].end(), b);
      if (itr != A[j].end()) {
        size_t idx = distance(A[j].begin(), itr);
        A[j][idx] = 0;
      }
    }
  }

  REP(i, 3) {
    int sum = accumulate(A[i].begin(), A[i].end(), 0);
    if (sum == 0) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  REP(i, 3) {
    int sum = A[0][i] + A[1][i] + A[2][i];
    if (sum == 0) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  if (A[0][0] + A[1][1] + A[2][2] == 0) {
    cout << "Yes" << endl;
    return 0;
  } else if (A[0][2] + A[1][1] + A[2][0] == 0) {
    cout << "Yes" << endl;
    return 0;
  } else {
    cout << "No" << endl;
    return 0;
  }
}

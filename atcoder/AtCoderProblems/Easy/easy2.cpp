#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  double res;
  double N;
  cin >> N;
  vector<double> X = vector<double>(3);
  double C_1 = 0;
  double C_2 = 0;
  double P;
  REP(i, N) {
    cin >> X[i];
    C_1 += X[i];
    C_2 += X[i] * X[i];
  }
  P = round(C_1 / N);
  res = N * pow(P, 2) - 2 * C_1 * P + C_2;
  // res = C_2 - pow(C_1, 2) / N;
  //
  // if ((long long)C_1 % (long long)N != 0) {
  //   res += N * pow((round(C_1 / N) - (C_1 / N)), 2);
  // }
  cout << (long long)res << endl;
}

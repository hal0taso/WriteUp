#include <iostream>
#include <string>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  int n, m, x;
  cin >> n >> m >> x;
  int cost_l = 0;
  int cost_r = 0;
  int a;
  REP(i,m){
    cin >> a;
    if (a > x){
      cost_r ++;
    } else {
      cost_l ++;
    }
  }
  if (cost_r > cost_l){
    cout << cost_l << endl;
  } else {
    cout << cost_r << endl;
  }
  return 0;
}

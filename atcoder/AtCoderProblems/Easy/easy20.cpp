#include <iostream>
#include <set>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  int x;
  cin >> x;
  set<int> s;
  int cnt = 1;
  while(s.find(x) == s.end()){
    s.insert(x);
    if (x & 1){
      x += (x << 1) + 1;
    } else {
      x >>= 1;
    }
    cnt ++;
  }
  cout << cnt << endl;
  return 0;
}

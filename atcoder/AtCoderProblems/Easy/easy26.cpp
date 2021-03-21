#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
int main() {
  ull h, i, ans;
  cin >> h;
  for (i = 0; h > 0; h >>= 1) {
    i++;
  }
  ans = ((ull)1 << i) - 1;
  cout << ans << endl;
}

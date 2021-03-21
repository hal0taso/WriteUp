#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
int main() {
  long long n, k, q, i, ai;
  cin >> n >> k >> q;
  vector<long long> p(n, k - q);
  for (i = 0; i < q; i++) {
    cin >> ai;
    p[ai - 1]++;
  }
  for (i = 0; i < n; i++) {
    if (p[i] > 0)
      puts("Yes");
    else
      puts("No");
  }
  return 0;
}

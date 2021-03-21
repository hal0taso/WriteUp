#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
int main() {
  ull n, a, b, ans = 0;
  cin >> n >> a >> b;
  ans += n / (a + b) * a;
  if (n % (a + b) >= a)
    ans += a;
  else
    ans += (n % (a + b)) % a;
  cout << ans << endl;
}

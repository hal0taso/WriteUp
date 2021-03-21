#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
int main() {
  string w;
  vector<int> c(26, 0);
  cin >> w;
  for (auto s : w) {
    c[s - 'a']++;
  }
  for (int i = 0; i < 26; i++) {
    if (c[i] % 2) {
      puts("No");
      return 0;
    }
  }
  puts("Yes");
  return 0;
}

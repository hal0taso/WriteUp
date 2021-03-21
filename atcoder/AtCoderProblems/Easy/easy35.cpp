#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
int main() {
  string s;
  cin >> s;
  vector<int> c(26, 0);
  for (auto si : s) {
    c[si - 'a']++;
  }
  for (int i = 0; i < 26; ++i) {
    if (c[i] == 0) {
      cout << (char)('a' + i) << endl;
      return 0;
    }
  }
  cout << "None" << endl;
  return 0;
}

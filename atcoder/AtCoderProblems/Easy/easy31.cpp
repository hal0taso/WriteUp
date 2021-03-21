#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
int main() {
  string s, sub;
  cin >> s;
  int i;
  vector<int> cnt(26, 0);
  for (auto si : s) {
    i = si - 'a';
    if (cnt[i] > 0) {
      cout << "no" << endl;
      return 0;
    }
    cnt[i]++;
  }
  cout << "yes" << endl;
  return 0;
}

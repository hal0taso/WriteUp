#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
int main() {
  string a, b;
  cin >> a >> b;
  if (a.size() > b.size())
    puts("GREATER");
  else if (a.size() < b.size())
    puts("LESS");
  else {
    for (int i = 0; i < a.size(); i++) {
      if (a[i] - '0' > b[i] - '0') {
        puts("GREATER");
        break;
      } else if (a[i] - '0' < b[i] - '0') {
        puts("LESS");
        break;
      }
      if (i == a.size() - 1) {
        puts("EQUAL");
      }
    }
  }

  return 0;
}

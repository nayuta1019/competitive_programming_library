#include <iostream>
#include <map>

using namespace std;

/* nを素因数分解する */
map<long long, int> primefactor(long long n) {
  map<long long, int> ret;
  for (long long i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if (n != 1) ret[n] = 1;
  return ret;
}

int main() {
  int n;
  cin >> n;
  cout << n << ":";
  for (auto it : primefactor(n)) {
    while (it.second--) cout << " " << it.first;
  }
  cout << endl;

  return 0;
}
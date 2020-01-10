#include <iostream>

using namespace std;

const long long MOD = 1e9 + 7;

/* べき乗(mのn乗)を計算する関数.計算量はO(logn) */
template <typename T>
T modpow(T m, T n, const T &p) {
  if (n == 0) return 1;
  T ret = modpow(m * m % p, n / 2, p);
  if (n % 2) ret *= m;
  return ret % p;
}

int main() {
  long long m, n;
  cin >> m >> n;
  cout << modpow(m, n, MOD) << endl;

  return 0;
}
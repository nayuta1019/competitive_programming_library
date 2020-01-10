#include <iostream>

using namespace std;

// 正の整数nが与えられたとき1からnまでの自然数のうちnと互いに素なものの個数を求める
long long euler_phi(long long n) {
  long long ret = n;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      ret -= ret / i;
      while (n % i == 0) n /= i;
    }
  }
  if (n > 1) ret -= ret / n;
  return ret;
}

int main() {
  long long n;
  cin >> n;

  cout << euler_phi(n) << endl;

  return 0;
}
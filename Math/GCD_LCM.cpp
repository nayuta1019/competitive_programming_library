#include <iostream>
#include <vector>

using namespace std;

/* 最大公約数 */
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

/* 最小公倍数 */
long long lcm(long long a, long long b) {
  long long g = gcd(a, b);
  return a / g * b;  // Be careful not to overflow
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  long long res = a[0];
  for (int i = 1; i < n; i++) {
    res = lcm(res, a[i]);
  }

  cout << res << endl;

  return 0;
}
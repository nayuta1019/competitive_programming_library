#include <bits/stdc++.h>

using namespace std;

/* nの約数を列挙 */
vector<long long> divisors(long long n) {
  vector<long long> res;
  for (long long i = 1; i * i <= n; ++i) {
    if (n % i != 0) continue;
    res.push_back(i);
    if (n / i == i) continue;  // 上の行で追加済み。
    res.push_back(n / i);
  }
  return res;
}

int main() {
  long long n;
  cin >> n;
  vector<long long> yakusuu = divisors(n);
  sort(yakusuu.begin(), yakusuu.end());
  for (auto x : yakusuu) {
    cout << x << endl;
  }

  return 0;
}

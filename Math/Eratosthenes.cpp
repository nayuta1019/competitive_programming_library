/**
エラトステネスの篩
[0, n) の配列で，primes[i] != 0 のときiは素数，な表を作る
素数リストだけが欲しい場合は remove--erase すればよい
O(nloglogn)．
**/
#include <iostream>
#include <vector>

using namespace std;

/* 素数かどうか判定. 素数 => true */
bool is_prime(long long n) {
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

/* エラトステネスの篩 */
vector<int> sieve_of_eratosthenes(int n) {
  vector<int> primes(n + 1, 0);

  for (int i = 2; i <= n; i++) primes[i] = i;

  for (int i = 2; i * i <= n; i++) {
    if (0 == primes[i]) continue;  //  0ならば素数ではない
    for (int j = i + i; j <= n; j += i) primes[j] = 0;  //  iの倍数を0にする
  }

  // primes.erase(remove(primes.begin(), primes.end(), 0), primes.end());

  return primes;
}

int main() {
  int N;
  cin >> N;

  int x, res = 0;
  while (N--) {
    cin >> x;
    res += is_prime(x);
  }
  cout << res << endl;

  return 0;
}
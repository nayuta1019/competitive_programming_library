#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1e9 + 7;

/* パスカルの三角形を使って二項係数テーブルを求める. O(n^2) */
template <typename T>
vector<vector<T>> binomial_table(T n) {
  vector<vector<T>> v(n + 1, vector<T>(n + 1, 0));
  for (int i = 0; i < v.size(); i++) {
    v[i][0] = 1;
    v[i][i] = 1;
  }
  for (int i = 1; i < v.size(); i++) {
    for (int j = 1; j < i; j++) {
      v[i][j] = (v[i - 1][j - 1] + v[i - 1][j]);
    }
  }
  return v;
}

/* べき乗(mのn乗)を計算する関数. O(logn) */
template <typename T>
T modpow(T m, T n, const T &p) {
  if (n == 0) return 1;
  T ret = modpow(m * m % p, n / 2, p);
  if (n % 2) ret *= m;
  return ret % p;
}
/* フェルマーの小定理を使って二項係数を計算. O(r) */
template <typename T>
T binomial(T n, T r, const T &p) {
  if (r > n - r) return binomial(n, n - r, p);
  T ansMul = 1;
  T ansDiv = 1;
  for (T i = 0; i < r; i++) {
    ansMul *= (n - i);
    ansDiv *= (i + 1);
    ansMul %= p;
    ansDiv %= p;
  }
  // ansDivの逆元
  T ans = (ansMul * modpow(ansDiv, p - 2, p)) % p;
  return ans;
}

/* 二項係数を計算. O(r) */
template <typename T>
T binomial(T n, T r) {
  if (r > n - r) return binomial(n, n - r);
  T ret = 1;
  for (T i = 0; i < r; i++) {
    ret *= (n - i);
    ret /= (i + 1);
  }
  return ret;
}

int main() {
  int n = 3;
  auto bt = binomial_table(n);
  vector<vector<long long>> mb(n + 1, vector<long long>(n + 1));
  vector<vector<long long>> b(n + 1, vector<long long>(n + 1));
  cout << "---binomial_table---\n";
  for (long long i = 0; i <= n; i++) {
    for (long long j = 0; j <= n; j++) {
      cout << bt[i][j] << " ";
      if (i < j) continue;
      mb[i][j] = binomial(i, j, MOD);
      b[i][j] = binomial(i, j);
    }
    cout << endl;
  }

  cout << "---mod_binomial---\n";
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      cout << mb[i][j] << " ";
    }
    cout << endl;
  }

  cout << "---binomial---\n";
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      cout << b[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}

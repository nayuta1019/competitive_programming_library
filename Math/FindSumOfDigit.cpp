/* 各桁の和を計算する関数 */
int findSumOfDigits(int n) {
  int sum = 0;
  while (n > 0) {  // n が 0 になるまで
    sum += n % 10;
    n /= 10;
  }
  return sum;
}
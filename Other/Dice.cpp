#include <bits/stdc++.h>

using namespace std;

struct Dice {
  int f[7];  // 0が上側、1が手前、2が右側、3が左側、4が奥側、5が下側
  Dice() {}
  void Xrot() { roll(0, 1, 5, 4); }  //手前が上側に来る
  void Yrot() { roll(0, 2, 5, 3); }  //右側が上側に来る
  void Zrot() { roll(1, 2, 4, 3); }  //右側が手前に来る

  void roll(int i, int j, int k, int l) {
    int tmp = f[i];
    f[i] = f[j];
    f[j] = f[k];
    f[k] = f[l];
    f[l] = tmp;
  }
  void move(char ch) {
    if (ch == 'E')
      for (int i = 0; i < 3; i++) Yrot();
    if (ch == 'W') Yrot();
    if (ch == 'N') Xrot();
    if (ch == 'S')
      for (int i = 0; i < 3; i++) Xrot();
  }
};

int main() {
  Dice dice;
  // T B U D L R
  cin >> dice.f[0] >> dice.f[5] >> dice.f[1] >> dice.f[4] >> dice.f[3] >>
      dice.f[2];
  int N;
  cin >> N;
  vector<int> p(N);
  for (int i = 0; i < N; i++) cin >> p[i];

  int ans = 0;
  // for (int i = 0; i < 3; i++) dice.Zrot();
  for (int i = 1; i < N; i++) {
    cout << "\nDice\n";
    cout << "T B U D L R\n";
    cout << dice.f[0] << " " << dice.f[5] << " " << dice.f[1] << " "
         << dice.f[4] << " " << dice.f[3] << " " << dice.f[2];
    cout << endl;
    if (p[i] == dice.f[4]) {  // D
      ans++;
      dice.move('S');
    } else if (p[i] == dice.f[3]) {  // L
      ans++;
      dice.move('E');
    } else if (p[i] == dice.f[2]) {  // R
      ans++;
      dice.move('W');
    } else if (p[i] == dice.f[5]) {  // B
      ans += 2;
      dice.move('W');
      dice.move('W');

    } else if (p[i] == dice.f[1]) {  // U
      ans++;
      dice.move('N');
    }
  }

  cout << ans << endl;

  return 0;
}
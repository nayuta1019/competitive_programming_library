//  ventor<pair<int, int>> の使い方
#include <iostream>
#include <vector>

using namespace std;

void printPairVector(vector<pair<int, int> > &vect) {
  for (auto x : vect) {
    cout << x.first << " " << x.second << endl;
  }
}

int main() {
  vector<pair<int, int> > vect2;
  vect2.push_back(make_pair(1, 30));
  vect2.push_back(make_pair(4, 20));
  vect2.push_back(make_pair(2, 100));
  vect2.push_back(make_pair(10, 10));
  vect2.push_back(make_pair(8, 7));

  // 昇順にソート
  sort(vect2.begin(), vect2.end());
  printPairVector(vect2);
  //  降順にソート
  sort(vect2.begin(), vect2.end(), greater<pair<int, int> >());
  printPairVector(vect2);

  return 0;
}
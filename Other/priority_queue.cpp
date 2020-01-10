#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct item {
  int id;
  string name;
  int price;
  item(int a, string b, int c) { id = a, name = b, price = c; }
};

void print(const vector<item> v) {
  cout << "\t--list--\n";
  for (auto x : v) {
    cout << "\t" << x.id << " " << x.name << " " << x.price << endl;
  }
  cout << "\n";
}

int main() {
  vector<item> ItemList;

  ItemList.push_back(item(3, "cup", 100));
  ItemList.push_back(item(1, "apple", 50));
  ItemList.push_back(item(2, "bread", 150));

  print(ItemList);

  sort(ItemList.begin(), ItemList.end(),
       [&](const item &i, const item &j) { return i.id < j.id; });  // idで昇順

  print(ItemList);

  sort(ItemList.begin(), ItemList.end(),
       [&](const item &i, const item &j) { return i.id > j.id; });  // idで降順

  print(ItemList);

  sort(ItemList.begin(), ItemList.end(), [&](const item &i, const item &j) {
    return i.name < j.name;
  });  // nameで昇順

  print(ItemList);

  sort(ItemList.begin(), ItemList.end(), [&](const item &i, const item &j) {
    return i.price < j.price;
  });  // priceで昇順

  print(ItemList);

  // sortに渡す関数オブジェクトとは違う?
  auto comp = [&](const item &i, const item &j) { return i.price < j.price; };
  priority_queue<item, vector<item>, decltype(comp)> que(comp);

  que.push(item(1, "abc", 10));
  que.push(item(2, "beet", 300));
  que.push(item(3, "cup", 100));
  while (!que.empty()) {
    item it = que.top();
    cout << it.id << " " << it.name << " " << it.price << endl;
    que.pop();
  }
}
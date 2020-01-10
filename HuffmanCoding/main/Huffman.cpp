/*
ハフマン符号化のプログラム
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

typedef pair<int, int> P;

struct node {
  int freq;
  char source_symbol;
  int id;
  int par;
  int left;
  int right;
};

using Tree = vector<node>;

int symbol;                  //符号の数
map<char, string> codelist;  //符号化されたビット列を格納する配列

void encodedfs(const Tree &huf, int v, int p, string code) {
  int lid = huf[v].left;   //ノードの左側の子のid
  int rid = huf[v].right;  //ノードの右側の子のid

  if (0 <= lid) {
    encodedfs(huf, lid, v, code + "0");
  }
  if (0 <= rid) {
    encodedfs(huf, rid, v, code + "1");
  }

  if (lid < 0 && rid < 0) {
    codelist[huf[v].source_symbol] = code;
  }
}

int main() {
  string s;
  // printf("input = ");
  cin >> s;

  map<char, int> Frequency;  //各符号の出現回数を格納

  Tree Huf;  //ハフマン符号木

  //符号の出現回数を求める
  for (int i = 0; i < s.size(); i++) Frequency[s[i]]++;
  symbol = Frequency.size();  //符号の数

  //ハフマン木に葉を追加
  auto it = Frequency.begin();
  while (it != Frequency.end()) {
    Huf.push_back({it->second, it->first, -1, -1, -1, -1});
    it++;
  }

  sort(Huf.begin(), Huf.end(),
       [](node a, node b) { return a.freq <= b.freq; });  //昇順にソート

  //符号木を構築していく
  auto comp = [](P a, P b) { return a.first >= b.first; };
  priority_queue<P, vector<P>, decltype(comp)> maketree_que(comp);  // freq, id

  for (int i = 0; i < Frequency.size(); i++) {
    maketree_que.push(P(Huf[i].freq, i));
    Huf[i].id = i;
  }

  /* 入力シンボルが1種類しかない場合 */
  if (symbol == 1) {
    P p = maketree_que.top();
    maketree_que.pop();
    Huf.push_back({p.first, '\0', (int)Huf.size(), -1, p.second, -1});
  }

  //根だけになるまでループ
  while (2 <= (int)maketree_que.size()) {
    P right = maketree_que.top();  //小
    maketree_que.pop();
    P left = maketree_que.top();  //大
    maketree_que.pop();

    // rightとleftをマージした節点を追加
    Huf.push_back({left.first + right.first, '\0', (int)Huf.size(), -1,
                   left.second, right.second});

    // rightとleftの親ノードの情報を更新
    int parId = (int)Huf.size() - 1;
    Huf[right.second].par = parId;
    Huf[left.second].par = parId;

    //節点をqueに追加
    maketree_que.push(P(Huf[parId].freq, parId));
  }

  /* 生成されたハフマン符号木 */
  /*
  printf("\nGenerated HuffmanTree\n");
  for (auto x : Huf) {
    cout << "id = " << x.id << " ";
    cout << "source symbol = " << x.source_symbol << " ";
    cout << "freq = " << x.freq << " ";
    cout << "parent = " << x.par << " ";
    cout << "left = " << x.left << " ";
    cout << "right = " << x.right;
    cout << endl;
  }
  */

  //符号化
  encodedfs(Huf, (int)Huf.size() - 1, -1, "");  //根から探索

  /* ハフマン符号の表 */
  /*
  printf("\nGenerated HuffmanCode\n");
  auto cit = codelist.begin();
  while (cit != codelist.end()) {
    cout << cit->first << " : " << cit->second << endl;
    cit++;
  }
  printf("\n");
  */

  //入力をビット列にする
  string encodeSign = "";
  for (int i = 0; i < s.size(); i++) {
    encodeSign += codelist[s[i]];
  }
  // cout << "Encode = " << encodeSign << "\n";
  cout << encodeSign.size() << endl;

  //復号化
  string decodeSign = "";
  int cur = (int)Huf.size() - 1;  //現在のノード
  for (int i = 0; i < encodeSign.size(); i++) {
    if (encodeSign[i] == '0') {
      cur = Huf[cur].left;
    }
    if (encodeSign[i] == '1') {
      cur = Huf[cur].right;
    }

    //葉の時
    if (Huf[cur].left < 0 && Huf[cur].right < 0) {
      decodeSign += Huf[cur].source_symbol;
      cur = (int)Huf.size() - 1;  //根に戻る
    }
  }
  /*
  cout << "Decode = " << decodeSign << "\n";
  printf("\n");
  */

  double AverageCodeWordLength = 0;
  for (int i = 0; i < symbol; i++) {
    AverageCodeWordLength += (double)Huf[i].freq / (double)s.size() *
                             (double)codelist[Huf[i].source_symbol].size();
  }

  /*
    cout << "AverageCodeWordLength = " << AverageCodeWordLength << endl;
    printf("\n");
  */

  return 0;
}
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
 
// 宣言
char maze[510][510]; // 迷路データ
int H; // 高さ
int W; // 幅
  
int sh, sw; // スタート地点
int gh, gw; // ゴール地点
vector< vector<int> > score(510, vector<int> (510, 110)); // 手数
bool visited[510][510]; // 訪問履歴
constexpr int dh[] = {0, 1, 0, -1, 1, 1, -1, -1, 2, 2, 2, -2, -2, -2, 0, -1, 1, 0, -1, 1};
constexpr int dw[] = {1, 0, -1, 0, 1, -1, 1, -1, 1, 0, -1, 1, 0, -1, 2, 2, 2, -2, -2, -2};
  
// 幅優先探索
void bfs(int i, int j) {
  // キューを準備
  deque<pair<int,int> > Q;
  // スタート地点のスコアを0にセット
  score[i][j] = 0;
  // スタート地点の座標をキューにプッシュ
  Q.push_back(make_pair(i, j));
  // キューが空になるまで処理を実行
  while(!Q.empty()) {
    // 探索の起点となる座標を記憶してからポップ
    pair<int,int> q = Q.front();
    Q.pop_front();
    int h = q.first;
    int w = q.second;
    // 起点を元に座標を移動
    for (int k = 0; k < 20; k++) {
      int nh = h + dh[k];
      int nw = w + dw[k];
      // 移動先が迷路の範囲外なら処理をスキップ
      if (nh < 0 || nh >= H || nw < 0 || nw >= W) {
        continue;
      }
      // 移動先が壁ならdequeの最後尾にプッシュ
      if (score[nh][nw] > (score[h][w] + 1) && maze[nh][nw] == '#') {
        Q.push_back(make_pair(nh, nw));
        // 移動先のスコアを起点のスコア+1にする
        score[nh][nw] = score[h][w] + 1;
      }
      // そうでなければdequeの先頭にプッシュ
      if (score [nh][nw] > score[h][w] && maze[nh][nw] != '#'){
        Q.push_front(make_pair(nh, nw));
        // 移動先のスコアを起点のスコアと同じにする
        score[nh][nw] = score[h][w];
      }
    }
  }
}
  
int main() {
  // 入力
  cin >> H >> W;
  // 迷路データ
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> maze[i][j];
      // スタート地点を記録
    }
  }
  
  int sh = 0, sw = 0, gh = H - 1, gw = W - 1;
  // 幅優先探索
  bfs(sh, sw);
  
  // 出力
  cout << score[gh][gw] << endl;
  return 0;
}
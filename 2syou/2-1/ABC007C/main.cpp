#include<bits/stdc++.h>
using namespace std;

#define step(i, s, n, d) for(int i=s; i<n; i+=d)
#define FOR(i,s,n) step(i,s,n,1)
#define rep(i,n) FOR(i,0,n)
#define gets(x) x; cin >> x;
#define puts(x) x; cout << x << endl;
#define list_input(x, n) x[n]; rep(i,n){ gets(x[i]);}
#define ll long long
typedef pair<int, int> P;

int N, M, sx, sy, gx, gy;
string maze[50]; //迷路が入る(. or #)
int d[50][51]; //最短経路が入る
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; //移動のベクトル

int bfs() {
  queue<P> que;
  rep(i, N){
    rep(j, M){
      d[i][j] = 100000;
    }
  }
  que.push(P(sx, sy));
  d[sx][sy] = 0; // 初期地点を入れる
  while (true) {
    P p = que.front(); que.pop(); //先頭を取り出す
    if (p.first == gx && p.second == gy) {
      break; //ゴールなら終わり
    }
    rep(i, 4){
      int nx = p.first + dx[i], ny = p.second + dy[i];
      if (0 <= nx && nx < N && 0 <= ny && ny < M && maze[nx][ny] != '#' && d[nx][ny] == 100000) {
        que.push(P(nx, ny));
        d[nx][ny] = d[p.first][p.second] +1;
      }
    }
  }
  return d[gx][gy];
}


int main(){
  cin >> N >> M >> sx >> sy >> gx >> gy;
  rep(i, N){
    cin >> maze[i];
  }
  sx -= 1; sy -= 1; gx -= 1; gy -= 1; //配列のindexとの調整
  int result = bfs();
  cout << result << endl;
}

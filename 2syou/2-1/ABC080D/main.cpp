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

string maze[50];
int N, M, sx = 0, sy = 0, gx, gy, f = 1000, s = 1000;
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
    if (f == p.first && s == p.second) {
      return -1;
    }else{
      f = p.first; s = p.second;
    }
    if (p.first == gx && p.second == gy) {
      break; //ゴールなら終わり
    }

    rep(i, 4){
      int nx = p.first + dx[i], ny = p.second + dy[i];
      if (0 >= nx && nx > N && 0 >= ny && ny > M) {
        cout << "oh" << endl;
      }
      if (0 <= nx && nx < N && 0 <= ny && ny < M && maze[nx][ny] != '#' && d[nx][ny] == 100000) {
        que.push(P(nx, ny));
        d[nx][ny] = d[p.first][p.second] +1;
      }
    }
  }
  return d[gx][gy];
}


int main(){
  int wall = 0;
  cin >> N >> M;
  gx = N-1, gy = M-1;
  rep(i, N){
    cin >> maze[i];
  }
  int shortest = bfs(); //最短経路
  if (shortest == -1) {
    cout << shortest << '\n';
    exit(0);
  }
  rep(i, N){
    rep(j, M){
      if (maze[i][j] == '#') {
        wall += 1;
      }
    }
  }
  int result = (N*M) - wall - (shortest+1);
  cout << result << '\n';
}

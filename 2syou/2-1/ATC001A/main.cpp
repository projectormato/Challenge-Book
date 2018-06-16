#include<bits/stdc++.h>
using namespace std;

#define step(i, s, n, d) for(int i=s; i<n; i+=d)
#define FOR(i,s,n) step(i,s,n,1)
#define rep(i,n) FOR(i,0,n)
#define list_input(x, n) x[n]; rep(i,n){ cin >> x[i];}
#define ll long long

int H, W, tx, ty, sx, sy;
string c[501];
bool already[501][501];

void dfs(int x, int y) {
  if (x < 0 || y < 0 || W <= x || H <= y || c[x][y] == '#' || already[x][y]) {
    return;
  }
  already[x][y] = true;

  dfs(x+1, y);
  dfs(x-1, y);
  dfs(x, y+1);
  dfs(x, y-1);

}

int main(){
  cin >> H >> W;
  rep(i, H){
    cin >> c[i]; // input
  }
  rep(i, H){
    rep(j, W){
      if (c[i][j] == 'g') {
        tx = i;
        ty = j;
      }
      if (c[i][j] == 's') {
        sx = i;
        sy = j;
      }
    }
  }
  dfs(sx,sy);
  string ans = already[tx][ty] ? "Yes" : "No";
  cout << ans << '\n';
}

#include<bits/stdc++.h>
using namespace std;

#define step(i, s, n, d) for(int i=s; i<n; i+=d)
#define FOR(i,s,n) step(i,s,n,1)
#define rep(i,n) FOR(i,0,n)
#define list_input(x, n) x[n]; rep(i,n){ cin >> x[i];}
#define ll long long

string field[10], tmp[10];

void dfs(int x, int y) {
  if (x < 0 || y < 0 || 10 <= x || 10 <= y || field[x][y] == 'x') {
    return;
  }
  field[x][y] = 'x';

  dfs(x+1, y);
  dfs(x-1, y);
  dfs(x, y+1);
  dfs(x, y-1);
}

int main(){
  int num = 0;
  char before = 'o';
  rep(i, 10){
    cin >> field[i];
  }
  rep(i, 10){
    tmp[i] = field[i];
  }
  rep(i, 10){
    rep(j, 10){
      before = field[i][j];
      field[i][j] = 'o'; // 置き換えてみる
      //ここから島の数を数える
      rep(k, 10){
        rep(l, 10){
          if (field[k][l] == 'o') {
            dfs(k, l);
            num += 1;
          }
        }
      }
      if (num == 1) {
        cout << "YES" << '\n';
        exit(0);
      }else{
        num = 0;
      }
      rep(i, 10){
        field[i] = tmp[i]; // 数える時に書き換えたのを戻す
      }
      field[i][j] = before; // 最初に置き換えたのを戻す
    }
  }
  cout << "NO" << '\n';
}

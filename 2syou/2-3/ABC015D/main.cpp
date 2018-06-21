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

int W, N, K;
int w[60], v[60]; //幅と重要度
int dp[60][10010][60]; //数、幅、上限数

int rec(int i, int j, int k) {
  if (dp[i][j][k] >= 0) { //-1ではない　→　すでに計算したことがある
    return dp[i][j][k]; //前回計算したものを返しておく。ここがメモ化したということ
  }
  int result;
  if (i == N || k == K) { //最後まできたらか、上限数に達していたら
    result = 0;
  }else if (j < w[i]) { //重さの上限よりも大きかったらはいらない
    result = rec(i+1, j, k);
  }else{ //計算する部分。入れる場合と入れない場合の両方を試すのは同じ
    result = max(rec(i+1, j, k), rec(i+1, j-w[i], k+1) + v[i]);
  }
  return dp[i][j][k] = result;
}

int main(){
  cin >> W >> N >> K;
  memset(dp, -1, sizeof(dp)); //-1でdpを初期化
  rep(i, N){
    cin >> w[i] >> v[i];
  }
  cout << rec(0, W, 0) << endl;

}

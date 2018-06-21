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

int N, W;
int v[101], w[101];
int dp[101][100001];
int rec(int i, int j) {
  if (dp[i][j] >= 0) { //-1ではない　→　すでに計算したことがある
    return dp[i][j]; //前回計算したものを返しておく。ここがメモ化したということ
  }
  int result;
  if (i == N) { //最後まできたら
    result = 0;
  }else if (j < w[i]) { //重さの上限よりも大きかったらはいらない
    result = rec(i+1, j);
  }else{ //計算する部分。入れる場合と入れない場合の両方を試すのは同じ
    result = max(rec(i+1, j), rec(i+1, j-w[i]) + v[i]);
  }
  return dp[i][j] = result;
}

int main(){
  cin >> N >> W;
  memset(dp, -1, sizeof(dp));
  rep(i, N){
    cin >> v[i] >> w[i];
  }
  cout << rec(0, W) << endl;
}

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

int N;
string x, y;
int dp[1010][1010];

int rec(int i, int j) {
  if (dp[i][j] >= 0) {
    return dp[i][j];
  }
  if (i == x.size() || j == y.size()) { //最後までいったら
    return 0;
  }else if (x[i] == y[j]) { //同じなら1プラスして次の文字へ
    return dp[i][j] = rec(i+1, j+1)+1;
  }else{ //同じじゃないなら、両方試す
    return dp[i][j] = max(rec(i+1, j), rec(i, j+1));
  }
}

int main(){
  cin >> N;
  rep(i, N){
    memset(dp, -1, sizeof(dp));
    cin >> x >> y;
    cout << rec(0, 0) << endl;
  }
}

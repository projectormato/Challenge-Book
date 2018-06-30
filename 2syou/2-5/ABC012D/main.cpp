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

int main(){
  int N, M, maxd = 0, ans = 1000000;
  cin >> N >> M;
  int a, b, c, dist[350][350];
  rep(i, N){
    rep(j, N){
      if (i == j) {
        dist[i][j] = 0;
      }else{
        dist[i][j] = 1000000;
      }
    }
  }
  rep(i, M){
    cin >> a >> b >> c;
    dist[a-1][b-1] = dist[b-1][a-1] = c;
  }
  rep(k, N){
    rep(i, N){
      rep(j, N){
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  rep(i, N){
    rep(j ,N){
      maxd = max(maxd, dist[i][j]);
    }
    ans = min(ans, maxd);
    maxd = 0;
  }
  cout << ans << endl;
}

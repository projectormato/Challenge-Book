#include<bits/stdc++.h>
using namespace std;

#define step(i, s, n, d) for(int i=s; i<n; i+=d)
#define FOR(i,s,n) step(i,s,n,1)
#define rep(i,n) FOR(i,0,n)
#define list_input(x, n) x[n]; rep(i,n){ cin >> x[i];}
#define ll long long

int main(){
  bool result = true;
  int N;
  cin >> N;
  int x[N+1][3];
  x[0][0] = x[0][1] = x[0][2] = 0;
  FOR(i, 1, N+1){
    cin >> x[i][0] >> x[i][1] >> x[i][2];
  }
  FOR(i, 1, N+1){
    int d = x[i][0] - x[i-1][0];
    int sa = abs( (x[i][1] - x[i-1][1]) + (x[i][2] - x[i-1][2]) );
    if (sa > d || d%2 != sa%2){
      result = false;
      break;
    }
  }
  string ans = result ? "Yes" : "No";
  cout << ans << endl;
}

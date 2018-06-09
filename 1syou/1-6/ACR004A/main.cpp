#include<bits/stdc++.h>
using namespace std;

#define step(i, s, n, d) for(int i=s; i<n; i+=d)
#define FOR(i,s,n) step(i,s,n,1)
#define rep(i,n) FOR(i,0,n)
#define list_input(x, n) x[n]; rep(i,n){ cin >> x[i];}
#define ll long long

int main(){
  double ans = 0; // this is answer
  int N;
  cin >> N;
  int x[N], y[N];
  rep(i, N){
    cin >> x[i] >> y[i];
  }
  rep(i, N){
    FOR(j, i+1, N){
      double d = sqrt(pow(x[j]-x[i],2) + pow(y[j]-y[i], 2));
      ans = max(ans, d);
    }
  }
  cout << fixed;
  cout << setprecision(6) << ans << endl;
}

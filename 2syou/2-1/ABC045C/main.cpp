#include<bits/stdc++.h>
using namespace std;

#define step(i, s, n, d) for(int i=s; i<n; i+=d)
#define FOR(i,s,n) step(i,s,n,1)
#define rep(i,n) FOR(i,0,n)
#define list_input(x, n) x[n]; rep(i,n){ cin >> x[i];}
#define ll long long

string S;
ll ans = 0;

void dfs(int i, ll add, ll sum) {
  add += (ll)(S[i] - '0');
  if (i == S.size() -1) {
    ans += sum + add;
    return;
  }
  dfs(i+1, 0, add+sum);
  dfs(i+1, add*10, sum);
}

int main(){
  cin >> S;
  dfs(0,0,0);
  cout << ans << endl;
}

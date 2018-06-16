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
  int N, ans = 0;
  cin >> N;
  N = 1000-N;
  int V[6] = {500, 100, 50, 10, 5, 1};
  rep(i, 6){
    ans += N/V[i];
    N %= V[i];
  }
  cout << ans << '\n';
}

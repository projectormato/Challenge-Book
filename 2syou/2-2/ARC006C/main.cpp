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
  int N, result = 0;
  cin >> N;
  int w[N], tower[N];
  list_input(w, N)
  rep(i, N){
    tower[i] = 100001;
  }
  rep(i, N){
    rep(j, N){
      if (tower[j] >= w[i]) {
        tower[j] = w[i];
        break;
      }
    }
  }
  rep(i, N){
    if (tower[i] != 100001) {
      result += 1;
    }
  }
  cout << result << '\n';
}

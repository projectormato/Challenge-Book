#include<bits/stdc++.h>
using namespace std;

#define step(i, s, n, d) for(int i=s; i<n; i+=d)
#define FOR(i,s,n) step(i,s,n,1)
#define rep(i,n) FOR(i,0,n)
#define list_input(x, n) x[n]; rep(i,n){ cin >> x[i];}
#define ll long long

int main(){
  string S;
  char op[2] = {'+', '-'};
  int AB, CD, ans;
  cin >> S;
  rep(i, 2){
    rep(j, 2){
      rep(k, 2){
        if (i == 0){
          AB = (S[0]-'0') + (S[1]-'0');
        }else{
          AB = (S[0]-'0') - (S[1]-'0');
        }

        if (k == 0) {
          CD = AB + (S[2]-'0');
        }else{
          CD = AB - (S[2]-'0');
        }

        if (j == 0) {
          ans = CD + (S[3]-'0');
        }else{
          ans = CD - (S[3]-'0');
        }

        if (ans == 7) {
          cout << S[0] << op[i] << S[1] << op[k] << S[2] << op[j] << S[3] << "=7" << '\n';
          exit(0);
        }
      }
    }
  }
}

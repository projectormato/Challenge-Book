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
  ll N, msum = 0, usum = 0, ans = -(1LL << 60);
  cin >> N;
  priority_queue<ll, vector<ll>, greater<ll> > mae_que;
  priority_queue<ll> usiro_que;
  ll a[N*3], mae_sum[N*3], usiro_sum[N*3];

  rep(i, N*3){
    cin >> a[i];
    if (N > i) {
      msum += a[i];
      mae_que.push(a[i]);
    }
    if (i >= N*2) {
      usum += a[i];
      usiro_que.push(a[i]);
    }
  }

  for(int i = N; i <= 2*N; i++){
    // cout << msum << "  " << i << endl;
    mae_sum[i] = msum;
    mae_que.push(a[i]);
    msum += a[i];
    msum -= mae_que.top();
    mae_que.pop();
  }

  usiro_sum[2*N] = usum;
  for(int i = 2*N-1; i >= N; i--) {
    usiro_que.push(a[i]);
    usum += a[i];
    usum -= usiro_que.top();
    usiro_que.pop();
    // cout << usum << "  " <<  i << endl;
    usiro_sum[i] = usum;
  }

  for(int i = N; i <= 2*N; i++) {
    ans = max(ans, mae_sum[i]-usiro_sum[i]);
  }

  cout << ans << endl;
}

#include <bits/stdc++.h>
using namespace std;
 
//CODED BY SUMIT KUMAR PRAJAPATI
typedef unsigned long long ull;
typedef long long ll;
 
ll powerfunction(ll a,ll b,ll m){

 	ll res=1;
 	while(b){
 		if(b&1)
 			res=(res*a)%m;
 		a=(a*a)%m;
 		b>>=1;
 	}
 	return res;
}
 
void solve(){
	
	
 
} 
 
 
 int main() {

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
   #else
       ios_base::sync_with_stdio(false);
      cin.tie(NULL);
        cout.tie(NULL);
   #endif

  ll t=1;
  cin>>t;
  while(t--)
  {
    ll a,b;
    cin>>a>>b;
    ll res=powerfunction(a,b,10);
    cout<<res<<'\n';
  
  }
 
  return 0;
 
}
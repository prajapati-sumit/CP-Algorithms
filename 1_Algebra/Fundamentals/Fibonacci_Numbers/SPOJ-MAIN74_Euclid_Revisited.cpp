#include <bits/stdc++.h>
using namespace std;
 
//CODED BY SUMIT KUMAR PRAJAPATI
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;

#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define PI 3.1415926535897932384626
#define pb push_back
#define mk make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define rep(i,n) for(ll i=0;i<n;i++)
#define repe(i,n) for(ll i=1;i<=n;i++)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define curtime chrono::high_resolution_clock::now()
#define timedif(start,end) chrono::duration_cast<chrono::nanoseconds>(end - start).count()
const int MX=1e5+5;
const ll MD=1e9+7;
const int MDL=99824453;
const ll INF=1e18;
auto time0 = curtime;
 
pl fib(ll n){
	if(n==0){
		return {0,1};
	}
	pl cur=fib(n>>1);
	ll nth=(cur.F*((2*cur.S+MD-cur.F)%MD))%MD;
	ll nth1=((cur.F*cur.F)%MD+(cur.S*cur.S)%MD)%MD;
	if(n&1)
		return {nth1,(nth+nth1)%MD};
	return {nth,nth1};
}

ll gcd(ll a,ll b){
	ll cnt=0;
	while(b){
		int temp=a;
		a=b;
		b=temp%b;
		cnt++;
	}
	return cnt;
} 

void brute(){

	pl ar[100];
	rep(i,100)
		ar[i]={MX,MX};
	FOR(i,0,40)
		FOR(j,0,i){
			int g=gcd(i,j);
			if(ar[g].F+ar[g].S>(i+j))
				ar[g].F=i,ar[g].S=j;

		}
	FOR(i,0,8)
		cout<<i<<"-> "<<ar[i].F<<" "<<ar[i].S<<" = "<<ar[i].F+ar[i].S<< '\n';
	cout<<"\n";

} 
 
void solve(){
	

	//cout<<gcd(55,89)<<"\n";
	ll n;
	cin>>n;
	ll ans;
	if(n==0)
		ans=0;
	else if(n==1)
		ans=2;
	else
		ans=fib(n+3).F;
  	//ans=fib(INF).F;
  	cout<<ans<<"\n";
 
} 
 
 
 int main() {
 	//brute();

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
   #else
       ios_base::sync_with_stdio(false);
      cin.tie(NULL);
        cout.tie(NULL);
   #endif

  srand(time(0));	

  time0 = curtime;
  ll t=1;
  cin>>t;
  while(t--)
    solve();
 
  return 0;
 
}
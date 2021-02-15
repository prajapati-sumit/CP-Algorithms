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
const int MD=1e9+7;
const int MDL=99824453;
auto time0 = curtime;
 
 
int gcd(int a,int b,int &x,int &y){

	if(b==0){
		x=1;
		y=0;
		return a;
	}
	int g=gcd(b,a%b,x,y);
	int temp=x;
	x=y;
	y=temp-(a/b)*y;
	return g;


}  
 
 
 
void solve(){
	
	int a,b,c;
	cin>>a>>b>>c;
	a=abs(a);
	b=abs(b);
	c=abs(c);
	int xm,ym,xM,yM;
	cin>>xm>>xM;
	cin>>ym>>yM;
	int x0,y0;
	int g=gcd(a,b,x0,y0);
	if(c%g){
		cout<<"0";
		return;
	}
	x0*=(c/g);
	y0*=(c/g);
	//cout<<x0<<" "<<y0<<'\n';
	int k_max=min((xM-x0)/(b/g),(y0-ym)/(a/g));
	int k_min=max(ceil((1.0*(xm-x0))/(b/g)),ceil((1.0*(y0-yM))/(a/g)));
	//assert(k_max>=k_min);
  	cout<<k_max-k_min+1<<'\n';
 
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

  srand(time(0));	

  time0 = curtime;
  ll t=1;
  cin>>t;
  while(t--)
    solve();
 
  return 0;
 
}
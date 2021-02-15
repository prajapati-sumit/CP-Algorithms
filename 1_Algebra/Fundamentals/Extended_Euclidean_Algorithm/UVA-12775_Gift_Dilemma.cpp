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
 
 
 
 
int A,B,C,P;
 
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
int f(int x,int y,int a,int b,int c){
	return a*x+b*y+c;
}
void solve(){
	
	cin>>A>>B>>C>>P;
	int x0,y0,w0,z0;
	int g=gcd(A,B,x0,y0);
	int G=gcd(g,C,w0,z0);
	int b1=(B/g),a1=(x0*C)/G,c1=(x0*w0*P)/G;
	int b2=-(A/g),a2=(y0*C)/G ,c2=(y0*w0*P)/G;
	int a3=-(g/G) ,b3=0, c3=(z0*P)/G;

	int x_up=(z0*P)/g;
	int y_up=((w0*P+(C*z0*P)/g)*(y0*g))/(A*G);
	int y_down=0;
	int x_down=ceil((w0*P)/(-1.0*C));

	// cout<<x_up<<"\n";
	// cout<<y_up<<"\n";
	// cout<<y_down<<"\n"<<x_down<<"\n";
	// cout<<"x= "<<(x0*w0*P)/G<<" + "<<(x0*C)/G<<"k + "<<(B/g)<<"t \n";

	// cout<<"y= "<<(y0*w0*P)/G<<" + "<<(y0*C)/G<<"k - "<<(A/g)<<"t \n";
	// cout<<"z= "<<(z0*P)/G<<" - "<<(g/G)<<"k \n";
 	int cnt=0;
 	FOR(x,x_down,x_up){
 		FOR(y,y_down,y_up){
 			
 			if(f(x,y,a1,b1,c1)>=0 && f(x,y,a2,b2,c2)>=0 && f(x,y,a3,b3,c3)>=0 ){
 				//cout<<x<<" "<<y<<'\n';
 				cnt++;
 			}
 		}
 	}
 	cout<<cnt<<'\n';
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
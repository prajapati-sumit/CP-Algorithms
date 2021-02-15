#include <bits/stdc++.h>
using namespace std;
 
//CODED BY SUMIT KUMAR PRAJAPATI
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int>  pii;
typedef pair<ll, ll>  pl;

#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define ss(s) scanf("%s",s)
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define ps(s) printf("%s\n",s)
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
#define printar(a,s,e) FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime chrono::high_resolution_clock::now()
#define timedif(start,end) chrono::duration_cast<chrono::nanoseconds>(end - start).count()
const int MX=1e5+5;
const int MD=1e9+7;
const int MDL=99824453;
auto time0 = curtime;
 
 
 
 
 
 
void solve(){
  
    int L,R;
    cin>>L>>R;
    int lim=sqrt(R);
    int ar[lim+1];
    vector<bool>isPrime(lim+1,true);
    for(int i=2;i<=lim;i++){
    	if(isPrime[i])
    		for(int j=i*i;j<=lim;j+=i)
    			isPrime[j]=false;
    }
    isPrime[1]=false;
    vector<int>primes;
    repe(i,lim)
    	if(isPrime[i])
    		primes.pb(i);

    std::vector<int> res(R-L+1,true);	
    for(int p:primes){
    	//cout<<p<<" ->";
    	int i=L;
    	if(L%p!=0)
    		i+=(p-L%p);
    	i=max(i,2*p);
    	//cout<<i<<"\n";
    	for(;i<=R;i+=p){
    		res[i-L]=false;
    	}
    }
    //cout<<'\n';
    if(L==1)
    	res[0]=false;
    FOR(i,0,R-L){
    	//cout<<res[i]<<" ";
    	if(res[i])
    		cout<<(L+i)<<"\n";
    }

  	cout<<"\n";
 
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
    
    auto timeend=curtime;
    auto extime=timedif(time0,timeend)*1e-9;
    cerr<<"Execution Time: "<<extime<<" sec\n";
    return 0;
 
}
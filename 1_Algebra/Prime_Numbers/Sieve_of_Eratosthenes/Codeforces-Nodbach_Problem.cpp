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
 const int MX=1e3+1;
 const int MD=1e9+7;
 const int MDL=99824453;
 auto time0 = curtime;
 int res[MX];

 vector<bool>isPrime(MX,true);
 std::vector<int> primes;

void init(){
 	for(int i=2;i*i<=MX;i++){
 		if(isPrime[i]){
 			for(int j=i*i;j<=MX;j+=i)
 				isPrime[j]=false;
 		}
 	}
 	for(int i=2;i<MX;i++)
 		if(isPrime[i])
 			primes.pb(i);
 	for(int i=1;i<primes.size();i++){
 		int s=1+primes[i-1]+primes[i];
 		if(isPrime[s])
 			res[s]=1;
 	}
 	FOR(i,1,MX-1){
 		res[i]+=res[i-1];
 	}


 }
  
  
  
  
  
void solve(){
   
    int n,k;
    cin>>n>>k;
    if(res[n]>=k)
    	cout<<"YES";
   	else cout<<"NO";
   	cout<<'\n';
   
  
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
     //cin>>t;
     init();
     while(t--)
         solve();
     
     auto timeend=curtime;
     auto extime=timedif(time0,timeend)*1e-9;
     cerr<<"Execution Time: "<<extime<<" sec\n";
     return 0;
  
 }
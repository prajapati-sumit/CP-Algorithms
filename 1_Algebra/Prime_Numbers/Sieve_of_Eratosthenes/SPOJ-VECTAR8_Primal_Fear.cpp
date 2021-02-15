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
const int MX=1e6+1;
const int MD=1e9+7;
const int MDL=99824453;
auto time0 = curtime;
vector<bool>isPrime(MX,true); 
vector<int>primes;
int res[MX];
 
void init(){


    int n=MX-1;
    
    isPrime[0] =false;
    isPrime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
    rep(i,MX)
        if(isPrime[i])
            primes.push_back(i);
    
    for(auto x:primes){
        bool flag=true;
        int temp=x;
        string y;
        while(true){
            y=to_string(temp);
            auto it=y.begin();
            y.erase(it);
            if(y.length()==0)
                temp=0;
            else
                temp=stoi(y);
            if(temp==0)
                break;
            if(isPrime[temp]==false || *it=='0' ){
                flag=false;
                break;
            }
        }
        if(flag){
            res[x]=1;
            
        }
    }
    
    repe(i,MX-1)
        res[i]+=res[i-1];

} 
 
 
void solve(){
    int n;
    cin>>n;
    cout<<res[n]<<"\n";
    
 
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
    init();
    while(t--)
        solve();
    
    
    return 0;
 
}

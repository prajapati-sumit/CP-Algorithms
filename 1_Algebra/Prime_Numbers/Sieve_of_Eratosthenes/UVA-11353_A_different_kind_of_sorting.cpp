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
const int MX=2e6+1;
const int MD=1e9+7;
const int MDL=99824453;
auto time0 = curtime;
 
pii res[MX];

int n=5,LPF[MX];
 
void init(){
	repe(i,MX-1)
		LPF[i]=i;
	for(int i=2;i*i<=MX;i++){
		if(LPF[i]==i){
			for(int j=i*i;j<=MX;j+=i)
				LPF[j]=i;
		}
	}
	repe(i,MX-1){
		int cnt=0,cur=i;

		while(cur>1){
			cnt++;
			cur/=LPF[cur];
		}
		res[i]={cnt,i};
	}
	sort(res+1,res+MX);

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
    while(cin>>n){

    	if(n==0)
    		break;
    	cout<<"Case "<<t<<": ";
    	cout<<res[n].S<<"\n";
    	t++;
    }
    //cout<<res[MX-1].S<<'\n';
    auto timeend=curtime;
    auto extime=timedif(time0,timeend)*1e-9;
    cerr<<"Execution Time: "<<extime<<" sec\n";
    return 0;
 
}
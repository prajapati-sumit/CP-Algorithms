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
 
 
 
int n,m;
bool isOn[MX];
int LPF[MX]; 
 
void solve(){

	FOR(i,1,MX-1)
		LPF[i]=i;
	for(int i=2;i*i<=MX;i++)
	{
		if(LPF[i]==i){
			for(int j=i*i;j<MX;j+=i)
				if(LPF[j]==j)
					LPF[j]=i;
		} 
	}

    map<int,set<int>>mp;
	
    cin>>n>>m;

    repe(i,m){
    	char ch;
    	int cur;
    	cin>>ch>>cur;
    	if(ch=='+'){
    		if(isOn[cur]){
    			cout<<"Already on";
    		}
    		else{
    			bool flag=true;
    			int temp=cur,cur_lpf=LPF[cur],con;
    			while(temp>1){
    				if(mp[cur_lpf].size()!=0){
    					con=*mp[cur_lpf].begin();
    					flag=false;
    					break;
    				}
    				while(temp%cur_lpf==0)
    					temp/=cur_lpf;
    				cur_lpf=LPF[temp];

    			}
    			if(flag)
    			{
    				temp=cur;
    				cur_lpf=LPF[cur];
    				while(temp>1){
    					
    					mp[cur_lpf].insert(cur);
	    				while(temp%cur_lpf==0)
	    					temp/=cur_lpf;
	    				cur_lpf=LPF[temp];
  
    				}
    				
    				cout<<"Success";
    				isOn[cur]=true;
    			}
    			else
    				cout<<"Conflict with "<<con;
    			

    		}

    	}
    	else{
    		if(isOn[cur]){
    			int temp=cur,cur_lpf=LPF[cur];
				while(temp>1){
					
					mp[cur_lpf].erase(cur);
    				while(temp%cur_lpf==0)
    					temp/=cur_lpf;
    				cur_lpf=LPF[temp];

				}
    			isOn[cur]=false;
    			cout<<"Success";
    		}
    		else
    			cout<<"Already off";
    	}
    	cout<<'\n';
    }
  
 
} 
//7 6 3
 
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
    while(t--)
        solve();
    
    auto timeend=curtime;
    auto extime=timedif(time0,timeend)*1e-9;
    cerr<<"Execution Time: "<<extime<<" sec\n";
    return 0;
 
}
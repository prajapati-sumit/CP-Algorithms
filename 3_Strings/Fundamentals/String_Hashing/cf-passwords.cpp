//~ author      : Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define ll                  long long
#define int                 long long
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define pb                  push_back
#define mk                  make_pair
#define ff                  first
#define ss                  second
#define all(a)              a.begin(),a.end()
#define trav(x,v)           for(auto &x:v)
#define rep(i,n)            for(int i=0;i<n;i++)
#define repe(i,n)           for(int i=1;i<=n;i++)
#define read(a,n)           rep(i,n)cin>>a[i]
#define reade(a,n)          repe(i,n)cin>>a[i]
#define FOR(i,a,b)          for(int i=a;i<=b;i++)
#define printar(a,s,e)      FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()




auto time0 = curtime;
const int MD = 1e9 + 9;
const int MDL = 998244353;
const int INF = 1e9;
const int MX = 1e6 + 5;


int p = 31;

int pref_hash[MX];
int powp[MX];
void solve() {

    string s;
    cin >> s;
    int n = s.length();
    powp[0] = 1;
    repe(i, n)
    powp[i] = p * powp[i - 1] % MD;
    int pi[n] = {0};
    // Prefix Function
    repe(i, n - 1) {
        int j = pi[i - 1];

        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];

        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    pref_hash[0] = s[0] - 'a'+1;
    repe(i, n - 1)
        pref_hash[i] = ((s[i]-'a'+1) * powp[i] + pref_hash[i - 1]) % MD;

    vector<pii>consider;
    int cur = pi[n - 1];
    while (cur > 0) {
        consider.pb({cur, pref_hash[cur - 1]});
        cur = pi[cur - 1];
    }

    for (auto &con : consider) {
        int len = con.ff, hash = con.ss;
        for (int i = 1; i + len - 1 < n - 1; i++) {
            int cur_hash = (pref_hash[i+len-1]+MD-pref_hash[i-1])%MD;
            // if(i==6){
            //     cout<<s.substr(i,len)<<" "<<cur_hash<<" "<<(powp[i]*hash) % MD<<'\n';
            // }
            if (cur_hash == ((powp[i]*hash) % MD)) {
                rep(i, len)
                cout << s[i];
                return;
            }
        }
    }
    cout << "Just a legend";


}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;
    srand(time(NULL));
    int t = 1;
    // cin>>t;
    repe(tt, t) {
        // cout<<"Case #"<<tt<<": ";
        solve();
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}
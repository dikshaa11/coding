#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
#include <list>
#include <map>
#include <utility>
#include <vector>
#include <set>
#include <string>
#include <queue>
using namespace std;

#define ll long long int
#define INF 1000000007
#define INFLL 1000000000000000011LL
#define pb(x) push_back(x)
#define mp make_pair
#define fi first
#define se second
#define vi vector
#define gtl(x) getline(cin, (x))
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)((a).size())
#define setv(x,a) memset(x,a,sizeof(x))
#define ull unsigned long long int 

ll PowMod(ll n, ll m, ll md)
{
    // cout<<"n = "<<n<<" m = "<<m<<" md = "<<md<<endl;
    ll ret = 1;
    ll a = m;
    // ll md = mdd;
    ll t;
    // cout<<"a = "<<a<<" md = "<<md<<endl;
    while (n > 0) {
        if (n & 1) ret = (md+((md+ret)%md)*1ull*((md+a)%md))%md;
        t = (md+a)%md;
        // cout<<"t = "<<t<<endl;
        a = (md+((t)*1ull*(t)))%md;
        // if(a==0) return 0;
        // cout<<"ret = "<<ret<<" a = "<<a<<endl;
        n >>= 1;
    }
    return ret;
}

ll gcd(ll a, ll b) {
            if (a == 0) return b;
            if (b == 0) return a;
            if (a < 0) return gcd(-1 * a, b);
            if (b < 0) return gcd(a, -1 * b);
            if (a > b) return gcd(b, a);
            return gcd(b%a, a);
}

ll max(ll a, ll b) {
    return a>b?a:b;
}
ll min(ll a, ll b) {
    return a<b?a:b; 
}

int main() {
    int t;
    scanf("%d",&t);
    //ll INF = 1000000007;
    while(t--) {
      ll n,k,sum=0;
      // cin>>n>>k;
      scanf("%lld %lld",&n,&k);

      vector<pair<ll,ll> > a;
      ll x, s[n];
      for(int i=0;i<n;i++) {
        scanf("%lld",&x);
        a.pb(mp(x,0));
      }

      for(int i=0;i<n;i++) {
        scanf("%lld",&x);
        a[i].second=x;
        sum+=x;
      }

      sort(a.begin(),a.end());
      for(int i=0;i<n;i++) {
        if(i==0) s[i]=a[i].second;
        else s[i] = s[i-1]+a[i].second;
      }

      ll b[k];
      for(int i=0;i<k;i++) cin>>b[i];

      ll l,r=sum;
      for(int i=0;i<k;i++) {
        if(i%2) {
          r = l+b[i]-1;
        } else {
          l = r-b[i]+1;
        }
      }

      if(l>r) {
        cout<<0<<endl;
        continue;
      }
      // cout<<"l = "<<l<<" r = "<<r<<endl;    
      int i=0;
      for(;i<n;i++) {
        if(s[i]>=l) break;
      }
     
      int j=0;
      for(;j<n;j++) {
        if(s[j]>=r) break;
      }  

      if(i==j) {
        ll answer = a[i].first*(r-l+1);
        cout<<answer<<endl;
        continue;
      } else {
        if(i>0)
        l = l-s[i-1];
        a[i].second = a[i].second-l+1;
        l = i;
        if(j>0)
        r = r-s[j-1];
        a[j].second = r;
        r = j;
      }
      sum=0;
      // cout<<"l = "<<l<<" r = "<<r<<endl;  
      for(i=l;i<=r;i++) sum = sum+a[i].first*a[i].second;

        cout<<sum<<endl;
    }
}
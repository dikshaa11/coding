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

ll MOD(ll a, ll power, ll m, ll d) {
	ll k = power;
	ll mul = d;
	ll tmp = 1;
	ll answer = 0;
	// cout<<"tmp = "<<tmp<<endl;
	// cout<<"mul = "<<mul<<endl;
	// bool check;
	while(k>0) {
		if(k&1) answer = ((answer%m)*(mul%m)+tmp%m)%m;
		tmp = ((tmp%m)*(mul%m)+tmp%m)%m;
		mul = ((mul%m)*(mul%m))%m;
		// if(k&1) answer = (answer*mul+tmp);
		// tmp = tmp*mul+tmp;
		// mul = mul*mul;
		// check=k&1;
		// cout<<"k&1 = "<<check<<endl;
		// cout<<"tmp = "<<tmp<<endl;
		// cout<<"mul = "<<mul<<endl;
		k>>=1;
	}



	// cout<<x<<endl;

	return answer;
}

ll phi(ll n)
{
    ll result = 1;
    for (ll i = 2; i < n; i++)
        if (__gcd(i, n) == 1)
            result++;
    return result;
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		ll a,n,m;
		cin>>a>>n>>m;

		int digits=0;

		if(a==0) {
			cout<<0<<endl;
			continue;
		}

		ll d = 1, dum =a;
		while(dum!=0) {
			dum = dum/10;
			digits++;
			d = d*10;
		}

		ll ans = (MOD(a,n,m,d)*a)%m;
		// cout<<"answer = "<<ans<<endl;
		cout<<ans<<endl;
		
	}
}


/*
int main() {
	int t;
	cin>>t;
	while(t--) {
		ll a,n,m;
		cin>>a>>n>>m;

		int digits=0;

		if(a==0) {
			cout<<0<<endl;
			continue;
		}

		ll d = 1, dum =a;
		while(dum!=0) {
			dum = dum/10;
			digits++;
			d = d*10;
		}

		ll answer = 0;
		digits = d;
		d = d%m;
		ll dMOD = (MOD(d,n,m)%m);
		dMOD = ((dMOD%m)-(1%m))%m;

		ll denom = digits-1;

		if(__gcd(denom,m)==1) {
			ll ph = phi(m);
			ph = ph-1;
			ph = (MOD(denom,ph,m)%m);
			answer = (((a%m)*(ph%m))%m * (dMOD%m))%m;

		} else  {
			ull b = m*denom;
			ll division = (a%b);
			division = division/denom;
			answer = ((division%m)*(dMOD%m))%m; 
		}
		cout<<answer<<endl;

	}
}*/
#include <bits/stdc++.h>
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

ll dp[10000000q1];

ll mx(ll a, ll b){
	return a>b?a:b;
}

void cal() {
	dp[0]=0;
	dp[1]=1;
	dp[2]=2;
	dp[3]=3;
	dp[4]=4;
	dp[5]=5;

	for(ll i=6;i<=100000001;i++) {
		dp[i] = mx(i,dp[i/2]+dp[i/3]+dp[i/4]);
	}
}


ll coin(ll n) {
	if(n<=100000001) return dp[n];

	return mx(n,coin(n/2)+coin(n/3)+coin(n/4));
}



int main() {
	// int t;
	
	setv(dp,0);
	cal();
	ll answer,n;
	
	while(scanf("%lld",&n)>0) {
		if(n<=100000001){
			cout<<dp[n]<<endl;
			// continue;
		} else {
			answer = coin(n);
			cout<<answer<<endl;
		}

	}

	return 0;

}
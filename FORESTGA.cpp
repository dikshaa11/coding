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

vector<ull> h;
vector<ull> r;
ull n,w,l;

bool can(ull month) {
	ull check = 0;
	for(ll i=0;i<n;i++) {
		if((ull)(h[i]+(ull)r[i]*month)>=l) {
			check+= (ull)(h[i]+(ull)r[i]*month);
			if(check>=w) break;
		}
	}	

	if(check>=w) return true;
	else return false;
}

ull binarySearch(ull left, ull right) {

	while(left<right) {
		ull mid = (left+right)/2;
		if(can(mid)) {
			right = mid;
		} else {
			left = mid+1;
		}
	}

	return left;
}

int main() {
	cin>>n>>w>>l;

	ull x,y;
	for(ll i =0;i<n;i++) {
		cin>>x>>y;
		h.pb(x);
		r.pb(y);
	}

	ull answer = binarySearch(0,1000000000000000011);
	cout<<answer<<endl;
}


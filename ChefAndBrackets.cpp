#include <bits/stdc++.h>
using namespace std;

int pos[101][101][201];



int main() {

	int n;
	cin>>n;

	int a[n];
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}

	int dp[n+1][n+1];

	for(int i=0;i<=n;i++) {
		for(int j=0;j<=n;j++) {
			if(i>=j) dp[i][j]=1;
			else dp[i][j]=0;
		}
	}

	for(int k=2;k<=n;k++) {
		for(int i=0;i<n-k+1;i++) {
			int j = i+1;
			if(a[i]<0) {
				while(j<i+k) {
					if(a[i]==-a[j]) {
						dp[i][i+k-1] += 2*(dp[i+1][j-1]*dp[j+1][i+k-1]);
						/*dp[i][i+k-1] += 2*(dp[i+1][j-1]);
						dp[i][i+k-1] += (dp[j+1][i+k-1]);*/
					}
					j++;
				}
			} else {
				// if(i<n-1)
				dp[i][i+k-1] += dp[i+1][i+k-1];
			}
			if(dp[i][i+k-1]==0) dp[i][i+k-1]=1;

			cout<<i<<" "<<i+k-1<<" "<<dp[i][i+k-1]<<endl;
		}
	}

	for(int i=0;i<=n;i++) {
		for(int j=0;j<=n;j++) {
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}


	cout<<dp[0][n-1];

}

#include <bits/stdc++.h>
 
using namespace std ;
 
const int N = 3e5 + 10 ;
int T , n , m , k , a[N] , b[210] ;
long long sum[N] , dp[N] ;
 
int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0); cout.tie(0) ;
    
    cin>>T ;
    for(int temp=0 ; temp<T ; temp++){
        cin>>n>>m ;
        
        for (int i = 1; i <= n; i++){
            cin>>a[i];
            sum[i] = sum[i-1] + a[i];
        
        }
        
        for (int i = 1; i <= m; i++)
            cin>>b[i];
        
        for (int i = 1 ; i + b[m] - 1 <= n ; i++)
            dp[i] = sum[i + b[m] - 1] - sum[i-1];
        
        for (int i = m-1 ; i ; --i){
            deque<int> q;
            cout<<"amit"<<endl;
            
            for (k = 2 ; k + b[i+1] - 1 < b[i] ; k++){
                while(!q.empty() && dp[q.back()] <= dp[k])
                    q.pop_back();
                q.push_back(k);
            }
            
            for (int j = 1 ; j + b[i] - 1 <= n ; j++){
                if(j > 1){
                    while(!q.empty() && dp[q.back()] <= dp[k])
                        q.pop_back() ;
                    q.push_back(k++) ;
                }
                while(q.front() <= j)
                    q.pop_front() ;
                dp[j] = sum[j + b[i] - 1] - sum[j - 1] - dp[q.front()] ;
            }
        }
        long long ans = 0 ;
        for (int i = 1 ; i + b[1] - 1 <= n ; i++)
            ans = max(ans , dp[i]) ;
        cout << ans << "\n" ;
    }
    return 0 ;
} 
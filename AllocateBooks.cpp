#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <algorithm>

using namespace std;



bool ispossible(vector<int> a, long long int mid, int m,long long int mx)
{
    int count=1;
    
    if(mx>mid)
    return false;
    
    long long int sum=0;
    for(int i =0;i<a.size();)
    {
        if((sum + (long long)a[i]) > mid)
        {
            count++;
            sum=0;
        }else
        {
            sum = sum+(long long)a[i];
             i++;
        }
    }
    
    if(count<=m)
    return true;
    else
    return false;
    
    
}


int books(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    long long int start = 0,end=0;
    int n = A.size();
    int mx=INT_MIN;
    //vector<int> sum(A.size()+1,0);
    
    for(int i=0;i<n;i++)
    {
        end+= A[i];
        mx = max(A[i],mx);
       // sum[i+1] = sum[i]+A[i];
    }
    cout<<mx<<" mx "<<endl;
    
    long long int ans = INT_MAX;
    ans = ans*INT_MAX;
    
    while(start<=end)
    {
        long long int mid = (start+end)/2;
        cout<<mid<<" mid "<<endl;
        if(ispossible(A,mid,B,mx))
        {
            cout<<ans<<" ans "<<mid<<" mid "<<endl;
            ans = (long long)min(ans,mid);
            end = mid-1;
        }else
        {
            start = mid+1;
        }
    }
    
    if(ans>=INT_MAX)
    return -1;
    else
    return ans;
}

int main()
{

    vector<int> A;
    A.push_back(12);
    A.push_back(34);
    A.push_back(67);
    A.push_back(90);
    
    long long int answer = books(A,2);
    cout<<answer<<endl;
}


//----------------------------------------------- Actual solution
/*bool ispossible(vector<int> a, long long int mid, int m,long long int mx)
{
    int count=1;
    
    if(mx>mid)
    return false;
    
    long long int sum=0;
    for(int i =0;i<a.size();)
    {
        if((sum + (long long)a[i]) > mid)
        {
            count++;
            sum=0;
        }else
        {
            sum = sum+(long long)a[i];
            i++;
        }
    }
    
    // agr number of books jyada hai students se to conditions <= hi lagegi
    //kyo isliye kyuki ye function sirf maximum pages ki condition ko hi check karta hai kitne number of students ko book mili 
    // ye nhi check karta hai 
    if(count<=m)
    return true;
    else
    return false;
    
    
}


int Solution::books(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    long long int start = 0,end=0;
    int n = A.size();
    int mx=INT_MIN;
    //vector<int> sum(A.size()+1,0);
    
    // important condition
    if(A.size()<B)
    return -1;
    
    for(int i=0;i<n;i++)
    {
        end+= A[i];
        mx = max(A[i],mx);
       // sum[i+1] = sum[i]+A[i];
    }
    
    long long int ans = INT_MAX;
    ans = ans*INT_MAX;
    
    while(start<=end)
    {
        long long int mid = (start+end)/2;
        if(ispossible(A,mid,B,mx))
        {
            ans = min(ans,mid);
            end = mid-1;
        }else
        {
            start = mid+1;
        }
    }
    
    if(ans>INT_MAX)
    return -1;
    else
    return ans;
}
*/

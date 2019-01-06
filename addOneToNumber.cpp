#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int> &A) {
    
    vector<int> ans;
    int sum =0;
    for(int i=0;i<A.size();i++)
    {
        sum = sum*10 + A[i];
    }
    
    sum = sum+1;

    cout<<sum<<" sum "<<endl;
    
    while(sum)
    {
        int x = sum%10;
        ans.push_back(x);
        sum=sum/10;
    }
    
    for(int i=0;i<(ans.size()/2);i++)
    {
        int t = ans[i];
        ans[i]=ans[ans.size()-1-i];
        ans[ans.size()-1-i] = t;
    }
    
    return ans;
}


int main()
{
     vector<int> a;
    int x;
    for(int i=0;i<12;i++)
    {
        cin>>x;
        a.push_back(x);
    }

    vector<int> A = plusOne(a);

     for(int i=0;i<A.size();i++)
    cout<<A[i]<<" ";
}

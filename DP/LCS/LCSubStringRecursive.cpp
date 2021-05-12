#include <bits/stdc++.h>
using namespace std;
int helper(int n,int m,string x,string y,int count);
int dp[101][101];
int main()
 {
    // added the two lines below for faster input
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        string x,y;
        cin>>x>>y;

        int m=x.size(),n=y.size();
        memset(dp,-1,sizeof(dp));

        int result=helper(m,n,x,y,0);
        cout<<result<<'\n';
        
    }
	return 0;
}

//only recursion
int helper(int m,int n,string x,string y,int count)
{
    if(m==0 || n==0) return count;

    if(x[m-1]==y[n-1]){
        return helper(m-1,n-1,x,y,count+1);
    }

    return max(count , max(helper(m-1,n,x,y,0),helper(m,n-1,x,y,0)) );

}


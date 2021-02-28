#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

// Returns the maximum value that  
// can be put in a knapsack of capacity W 
int knapSack(int wt[], int val[], int W, int n)
{
    int dp[n+1][W+1];
    for(int i=0;i<(n+1);i++){
      for(int j=0;j<(W+1);j++){

        if(i==0) dp[i][j]=0;
        else if(j==0) dp[i][j]=0;
        else if(wt[i-1]<=j) dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], 
                                                      dp[i-1][j]);

        else dp[i][j]=dp[i-1][j];
      }
    }
    // for(int i=0;i<(n+1);i++){
    //   for(int j=0;j<(W+1);j++){
    //     cout<<dp[i][j]<<" ";
    //   }cout<<'\n';
    // }
  return dp[n][W];
}

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
        int n, W;
        cin>>n>>W;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
         cin>>wt[i];
        
        //calling method knapSack()
        cout<<knapSack(wt,val,W,n)<<endl;
        
    }
	return 0;
}
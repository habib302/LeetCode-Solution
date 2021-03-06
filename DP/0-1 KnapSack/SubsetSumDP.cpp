#include <bits/stdc++.h>
using namespace std;
bool SubsetSum(int nums[],int n,int sum);

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
      int n, sum;
      cin>>n>>sum;
        
      int nums[n];
      
      //inserting the values
      for(int i=0;i<n;i++)
        cin>>nums[i];
      
      if(SubsetSum(nums,n,sum)){
        cout<<"True"<<'\n';
      }else{
        cout<<"False"<<'\n';
      }

    }
	return 0;
}

bool SubsetSum(int nums[],int n,int sum)
{
  bool dp[n+1][sum+1];
  
  for(int i=0;i<(n+1);i++){
    for(int j=0;j<(sum+1);j++){
      
      if(i==0 && j==0) dp[i][j]=true;

      else if(i==0) dp[i][j]=false;
      
      else if(j==0) dp[i][j]=true;

      else if(nums[i-1]<=j){
        dp[i][j]= (dp[i-1][j-nums[i-1]]) || (dp[i-1][j]);
      }
      
      else{
        dp[i][j]= dp[i-1][j];
      }
      
    }
  }

  // for(int i=0;i<(n+1);i++){
  //   for(int j=0;j<(sum+1);j++){
  //     cout<<dp[i][j]<<" ";
  //   }
  //   cout<<'\n';
  // }

  return dp[n][sum];
}
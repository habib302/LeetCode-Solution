#include <bits/stdc++.h>
using namespace std;
int targetSum(int arr[],int S);

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
      int n,S;
      cin>>n>>S;
        
      int nums[n];
      
      //inserting the values
      for(int i=0;i<n;i++)
        cin>>nums[i];
      
      cout<<targetSum(nums,S)<<'\n';
      

    }
	return 0;
}

int targetSum(int nums[],int S)
{
	int sum=0,n=sizeof(nums) / sizeof(nums[0]);;
  for(int i=0;i<n;i++){
    sum += nums[i];
  }
        
  if(S>sum) return 0;
  if((S+sum)%2 != 0) return 0;
        
  // here diff=S
  int sumS1= (S+sum)/2;

  int dp[n+1][sumS1+1];

  for(int i=0;i<(n+1);i++){
    for(int j=0;j<(sumS1+1);j++){
      if(i==0 && j==0) dp[i][j]=1;
      else if(i==0) dp[i][j]=0;
      else if(j==0) dp[i][j]=1;
      else if(nums[i-1]<=j) dp[i][j]= dp[i-1][j-nums[i-1]] + dp[i-1][j];
      else dp[i][j]= dp[i-1][j];
    }
  }
  
  return dp[n][sumS1];
}
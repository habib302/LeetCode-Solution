#include <bits/stdc++.h>
using namespace std;
int SubsetCount(int arr[],int n,int diff);

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
      int n,diff;
      cin>>n>>diff;
        
      int arr[n];
      
      //inserting the values
      for(int i=0;i<n;i++)
        cin>>arr[i];
      
      cout<<SubsetCount(arr,n,diff)<<'\n';
      

    }
	return 0;
}

int SubsetCount(int arr[],int n,int diff)
{
	int sum=0;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    
    int sumS1= (diff+sum)/2;
    //cout<<sum<<" "<<sumS1;
    int dp[n+1][sumS1+1];

    for(int i=0;i<(n+1);i++){
        for(int j=0;j<(sumS1+1);j++){
            if(i==0 && j==0) dp[i][j]=1;
            else if(i==0) dp[i][j]=0;
            else if(j==0) dp[i][j]=1;
            else if(arr[i-1]<=j) dp[i][j]= (dp[i-1][j-arr[i-1]]) + (dp[i-1][j]);
            else dp[i][j]= dp[i-1][j];
        }
    }

    // for(int i=0;i<(n+1);i++){
    //     for(int j=0;j<(sumS1+1);j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    // cout<<'\n';
    // }
    return dp[n][sumS1];
}
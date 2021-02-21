#include <bits/stdc++.h>
using namespace std;
int SubsetSumMinimum(int arr[],int n);

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
      int n;
      cin>>n;
        
      int arr[n];
      
      //inserting the values
      for(int i=0;i<n;i++)
        cin>>arr[i];
      
      cout<<SubsetSumMinimum(arr,n)<<'\n';
      

    }
	return 0;
}

int SubsetSumMinimum(int arr[],int n)
{
	int sum=0;
	for(int i=0;i<n;i++){
	    sum += arr[i];
	}

	bool dp[n+1][sum+1];
	for(int i=0;i<(n+1);i++){
	    for(int j=0;j<(sum+1);j++){
	        if(i==0 && j==0) dp[i][j]=true;
	        else if(i==0) dp[i][j]=false;
	        else if(i==0) dp[i][j]=true;
	        else if(arr[i-1]<=j) dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
	        else dp[i][j] = dp[i-1][j];
	    }
	}

	int diff=INT_MAX;
	for(int j=sum/2;j>=0;j--){
		if(dp[n][j]==true){
			diff= sum - (2*j);
			break;
		}
	}

	return diff;
}
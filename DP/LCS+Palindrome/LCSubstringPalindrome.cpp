#include <bits/stdc++.h>
using namespace std;
int LCSubstring(string x,int n);

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
        string x;
        cin>>x;

        int n=x.size();
        
        int result=LCSubstring(x,n);
        cout<<result<<'\n';
        
    }
	return 0;
}

int LCSubstring(string x,int n)
{   
    string y=x;
    reverse(y.begin(),y.end());

    int m=x.size(),len=0,r=0,c=0;
    //max length=0 hote pare,negative na
    int dp[n+1][m+1];

    for(int i=0;i<(n+1);i++){
        for(int j=0;j<(m+1);j++){
            if(i==0) dp[i][j]=0;
            else if(j==0) dp[i][j]=0;
            else if(x[i-1]==y[j-1]) {
                dp[i][j] = 1+dp[i-1][j-1]; 
                len=max(len,dp[i][j]);
                r=i,c=j;
            }
            else dp[i][j]= 0;
        }
    }

    for(int i=0;i<(n+1);i++){
        for(int j=0;j<(m+1);j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<'\n';
    }
    
    return len;
}
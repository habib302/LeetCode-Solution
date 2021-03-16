#include <bits/stdc++.h>
using namespace std;
void LCS(string x,string y,int n,int m);

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

        int n=x.size(),m=y.size();
        
        LCS(x,y,n,m);
        
    }
	return 0;
}

void LCS(string x,string y,int n,int m)
{
    bool dp[n+1][m+1];
    string r;
    for(int i=0;i<(n+1);i++){
        for(int j=0;j<(m+1);j++){
            if(i==0) dp[i][j]=false;
            else if(j==0) dp[i][j]=false;
            else if(x[i-1]==y[j-1]) {dp[i][j]=true; r.push_back(x[i-1]);}
            else dp[i][j] = dp[i][j-1] || dp[i-1][j];
        }
    }

    for(int i=0;i<(n+1);i++){
        for(int j=0;j<(m+1);j++){
            if(dp[i][j]==true) cout<<dp[i][j];
        }
        cout<<'\n';
    }
    
    cout<<r<<'\n';
}
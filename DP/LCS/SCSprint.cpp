#include <bits/stdc++.h>
using namespace std;
void SCS(string x,string y,int n,int m);

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
        SCS(x,y,n,m);
        
    }
	return 0;
}

void SCS(string x,string y,int n,int m)
{
    int dp[n+1][m+1];
    
    for(int i=0;i<(n+1);i++){
        for(int j=0;j<(m+1);j++){
            if(i==0) dp[i][j]=0;
            else if(j==0) dp[i][j]=0;
            else if(x[i-1]==y[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]= max(dp[i][j-1],dp[i-1][j]);
        }
    }
    int i=n,j=m;
    string s="";
    while(i>0 && j>0){
        if(x[i-1]==y[j-1]){
            s.push_back(x[i-1]);
            i--;j--;
        }else if(dp[i][j-1]>dp[i-1][j]){
            s.push_back(y[j-1]);
            j--;
        }else{
            s.push_back(x[i-1]);
            i--;
        }
    }

    reverse(s.begin(),s.end());
    cout<<s<<'\n';
    return;
}
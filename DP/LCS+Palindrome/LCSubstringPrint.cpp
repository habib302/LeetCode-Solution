#include <bits/stdc++.h>
using namespace std;
void LCSubstring(int n,int m,string x,string y);

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
        
        LCSubstring(m,n,x,y);
    }
	return 0;
}

void LCSubstring(int n,int m,string x,string y)
{
    int dp[m+1][n+1];
    int len=0; //max length=0 hote pare,negative na
    int r=0,c=0;
    for(int i=0;i<(m+1);i++){
        for(int j=0;j<(n+1);j++){
            if(i==0) dp[i][j]=0;
            else if(j==0) dp[i][j]=0;
            else if(x[i-1]==y[j-1]) {
                dp[i][j] = 1+dp[i-1][j-1]; 
                //len=max(len,dp[i][j]);
                if(dp[i][j]>len){
                    len=dp[i][j];
                    r=i;
                    c=j;
                }
            }
            else dp[i][j]= 0;
        }
    }

    string s="";

    while(dp[r][c] != 0){
        s.push_back(x[r-1]);
        r--;c--;
    }

    reverse(s.begin(),s.end());
    cout<<s<<'\n';
    return;
}
#include <bits/stdc++.h>
using namespace std;
int LCS(string x,string y,int n,int m);

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
        
        int result=LCS(x,y,n,m);
        cout<<result<<'\n';
        
    }
	return 0;
}

int LCS(string x,string y,int n,int m)
{
    if(n==0 || m==0){
        return 0;
    }

    if(x[n-1]==y[m-1]){
        return 1+LCS(x,y,n-1,m-1);
    }else{
        return max(LCS(x,y,n,m-1),LCS(x,y,n-1,m));
    }
}
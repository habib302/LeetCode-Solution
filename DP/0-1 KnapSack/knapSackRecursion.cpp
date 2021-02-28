#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

// Returns the maximum value that  
// can be put in a knapsack of capacity W 
int knapSack(int wt[], int val[], int W, int n)
{
    if(n==0) return 0;
    if(W==0) return 0;
    if(wt[n-1] <= W) 
        return max( val[n-1]+knapSack(wt, val, W-wt[n-1],n-1),
                             knapSack(wt, val, W        ,n-1));
    
    else return              knapSack(wt, val, W        ,n-1);

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
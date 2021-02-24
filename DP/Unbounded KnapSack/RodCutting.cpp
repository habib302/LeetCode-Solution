#include <bits/stdc++.h>
using namespace std;
int RodCutting(int length[], int price[], int W, int n);

int RodCutting(int length[], int price[], int W, int n)
{
    

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

      int n, W;
      cin>>n>>W;
      
      int length[n];
      int price[n];
      
      for(int i=0;i<n;i++)
        cin>>length[i];
      
      for(int i=0;i<n;i++)
        cin>>price[i];
      
      //cout<<RodCutting(wt,val,W,n)<<endl;

    }
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
void Solve();

int main(){
    
 // added the two lines below for faster input
 ios_base::sync_with_stdio(false); 
 cin.tie(NULL);
    
 //taking total testcases
 int t;
 cin>>t;
  while(t--){ 
    Solve();
  }  
	return 0;
}

void Solve(){
  
  int n, k;
  cin>>n;
  cin>>n>>k;

  vector<int> nums(n);
  //vector<string> nums(n);

  for(int i=0;i<n;i++){
    cin>>nums[i];
  }
  

  
  return ;
}
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>

using namespace std;
void Solve(vector<int> nums,int k);

int main(){
    
 // added the two lines below for faster input
 ios_base::sync_with_stdio(false); 
 cin.tie(NULL);
    
 //taking total testcases
 int t;
 cin>>t;
  while(t--){
  
    int n, k;
    cin>>n;
    //cin>>n>>k;
          
    vector<int> nums(n);
    //vector<string> nums(n);

    for(int i=0;i<n;i++){
      cin>>nums[i];
    }

    Solve(nums,k);

  }  
	return 0;
}

void Solve(vector<int> nums,int k){
  int len=nums.size();
  int n1=0,n2=0,a=0,b=0;

  for(int i=0;i<len;i++){

  }

  //cout<<"5"<<endl;
  return ;
}
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> sub;
void Solve(vector<int> nums,int n);
void printArray(vector<int> arr, int n) ;

void printArray(vector<int> arr, int n) 
{   vector<int> temp; 
	for (int i = 0; i < n; i++){ 
		cout << arr[i] << " ";
        temp.push_back(arr[i]); 
    }
    sub.push_back(temp);
	cout << endl; 
} 

// Recursive function to print all 
// possible subsequences for given array 
void printSubsequences(vector<int> arr, int index,vector<int> subarr) 
{ 
	// Print the subsequence when reach 
	// the leaf of recursion tree 
	if (index == arr.size()) 
	{ 
		int l = subarr.size(); 

		// Condition to avoid printing 
		// empty subsequence 
		if (l != 0) 
			printArray(subarr, l); 
	} 
	else
	{ 
		// Subsequence without including 
		// the element at current index 
		printSubsequences(arr, index + 1, subarr); 

		subarr.push_back(arr[index]); 

		// Subsequence including the element 
		// at current index 
		printSubsequences(arr, index + 1, subarr); 
	} 
	return; 
} 

int main(){
    
 // added the two lines below for faster input
 ios_base::sync_with_stdio(false); 
 cin.tie(NULL);
    
 //taking total testcases
 int n;
 cin>>n;
 vector<int> arr(n);
 vector<int> b; 
 for(int i=0;i<n;i++){
    cin>>arr[i];
}
Solve(arr,n);

int t;
cin>>t;
while(t--){
  printSubsequences(arr, 0, b); 
  for(int i=0;i<sub.size();i++){
      for(int j=0;j<sub[0].size();j++){
          cout<<sub[i][j]<<" ";
      }
  }

}  
return 0;
}

void Solve(vector<int> nums,int n){

  for(int i=0;i<n;i++){

  }

  
  return ;
}

#include <bits/stdc++.h>
using namespace std;
vector<int> helper(vector<int> nums);

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
        int n;
        cin>>n;
        
        vector<int> nums(n);
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>nums[i];
        
        vector<int> ans=helper(nums);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<'\n';
    }
	return 0;
}

vector<int> helper(vector<int> nums){
    
    int n=nums.size();

    for(int i=0;i<n-1;i++){

        //even index
        if(i%2==0){
            if(nums[i] >= nums[i+1]){
                swap(nums[i],nums[i+1]);
            }
        }
        //odd index
        else{
            if(nums[i] <= nums[i+1]){
                swap(nums[i],nums[i+1]);
            }
        }
    }
    return nums;
}
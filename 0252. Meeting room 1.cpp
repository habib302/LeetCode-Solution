#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;
bool helper(vector<vector<int>> nums);

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

        // vector<vector<int>> nums={
        //     {2,4},
        //     {7,10},
        // };

        vector<vector<int>> nums={
            {0,30},
            {5,10},
            {15,20}
        };
        
        bool ans=helper(nums);
        
        cout<<ans<<'\n';
    }
	return 0;
}
bool helper(vector<vector<int>> nums){

    sort(nums.begin(),nums.end());

    int n=nums.size();
    vector<int> temp=nums[0];

    for(int i=1;i<n;i++){
        
        if(temp[1]> nums[i][0]){
            return false;
        }
        
        temp=nums[0];
    }

    return true;
}
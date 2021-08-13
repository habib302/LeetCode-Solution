#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> NGER(vector<int> nums);

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
        int n;
        cin>>n;
        
        vector<int> nums(n);
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>nums[i];
        
        vector<int> ans=NGER(nums);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<'\n';
    }
	return 0;
}

vector<int> NGER(vector<int> nums){
    int n=nums.size();
    vector<int> res(n,-1);

    stack<int> st;
    for(int i=0;i<n;i++){

        //step 1
        while(st.size()>0 && nums[st.top()] < nums[i]){
            res[st.top()]=nums[i];
            st.pop();
        }

        //step 2
        st.push(i);
    }


    return res;
}
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> helper(vector<vector<int>> nums,int n);

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
        
        //query
        vector<vector<int>> updates={{1,3,2},{2,4,3},{0,2,-2}};
        
        vector<int> ans=helper(updates,n);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<'\n';
    }
	return 0;
}

vector<int> helper(vector<vector<int>> updates,int n){
    
    vector<int> res(n+1,0);

    for(int i=0;i<updates.size();i++){
        int start=updates[i][0];
        int end=updates[i][1];
        int inc=updates[i][2];

        res[start] += inc;
        res[end+1] += (-inc);
    }

    int sum=0;
    for(int i=0;i<res.size();i++){
        sum += res[i];
        res[i]=sum;
    }

    res.pop_back();

    return res;
}